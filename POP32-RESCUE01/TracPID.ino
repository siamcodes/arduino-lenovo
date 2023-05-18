void TracPID()  {
  int Output, LeftSpeed, RightSpeed, KpTemp;

  if (abs(Error) <= 1) KpTemp = 1; else KpTemp = Kp;
  Output = (KpTemp * Error) + (Ki * SumError) + (Kd * (Error - PreError));

  LeftSpeed = LeftBaseSpeed + Output;
  RightSpeed = RightBaseSpeed - Output;

  /*
    if (LeftSpeed > MaxSpeed) LeftSpeed = MaxSpeed;
    else if (LeftSpeed < -MaxSpeed) LeftSpeed = -MaxSpeed;
    //else if (LeftSpeed < 0) LeftSpeed = 0; //new pid
    if (RightSpeed > MaxSpeed) RightSpeed = MaxSpeed;
    else if (RightSpeed < -MaxSpeed) RightSpeed = -MaxSpeed;
    //else if (RightSpeed < 0) RightSpeed = 0; //new pid
  */

  if (LeftSpeed > MaxSpeed) LeftSpeed = MaxSpeed;
  if (LeftSpeed < -MaxSpeed) LeftSpeed = -MaxSpeed;
  if (RightSpeed > MaxSpeed) RightSpeed = MaxSpeed;
  if (RightSpeed < -MaxSpeed) RightSpeed = -MaxSpeed;

  motor(1, LeftSpeed);
  motor(2, LeftSpeed);
  motor(3, RightSpeed);
  motor(4, RightSpeed);

  PreError = Error;
  SumError += Error;
}


void TracJCStop() { //เดินถึงเส้นและออกจากฟังก์ชั่น
  InitialSpeed();
  CalError();
  while (Error < 99) {
    TracPID();
    StartTimer();
    while ((ReadTimer() < Kt) && Error < 100) {
      CalError();
    }
  }
}


void TracJC() {  //เดินถึงเส้นที่ไม่ใช่ขอบ และถอยแบบจูน ใช้กับรอยต่อระหว่าขาว-ดำ
  TracJCStop();
  ForwardSpeedTime(SlowSpeed, 1);
  CalError();
  while ((abs(Error) > 1 )) {
    CalError();
  }
  MotorStop();
  BackwardBalanceF(); //BackwardBalanceF();
  BackwardSpeedTime(SlowSpeed, 50);
}


void TracJC0() { //เดินถึงเส้นและถอยแบบไม่จูน
  TracJCStop();
  MotorStop();
  BackwardSpeedTime(SlowSpeed, 200);  //ถ้าถอยไม่กลางช่องให้พิ่มลดค่าตัวเลข
}


void TracJC1() { //เดินถึงเส้นจูนขาเข้า และถอยแบบไม่จูน
  TracJCBlack();  //ตั้งลำตอนเข้า
  MotorStop();
  BackwardSpeedTime(SlowSpeed, 1);  //ออกตรงอย่างเดียว
  CalError();
  while (Error == 0) {   //เช็คว่าออกจากเส้นดำหรือยัง
    CalError();
  }
  delay(10);
  while (Error != 0) {  //เช็คว่าออกจากเส้นดำหรือยัง
    CalError();
  }
  delay(100);  //ออกมาก ออกน้อยแก้ตรงนี้
}


void TracJCBlack() {   //วิ่งเข้าหลุมดำหรือพื้นที่วางสีเขียว
  TracJCStop();
  ConvertADC();
  if ((L1 == 0) && (R1 == 1)) { //เจอดำข้างซ้าย

  }
}

void TracJCSpeedTime(int MotorSpeed, int Time) {
  BaseSpeed = MotorSpeed;
  TracJCStop();
  Forward();
  delay(Time);
  BaseSpeed = Speed;
  InitialSpeed();
}


void TracSpeedTime(int TracSpeed, int TracTime) {
  BaseSpeed = TracSpeed;
  InitialSpeed();
  StartTimer();
  CalError();
  while (ReadTimer() < TracTime) {
    TracPID();
    delay(Kt);
  }
}
