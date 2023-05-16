/*
void TracPID()      //แทรกเส้นแบบ PID
{
  int Output, LeftOutput, RightOutput, KpTemp;

  if (abs(Error) <= 3) KpTemp = 1; else KpTemp = Kp;

  Output = (KpTemp * Error) + (Ki * Integral) + Kd * (Error - PreError);  //สมการ PID

  LeftOutput = LeftSpeed + Output;        //ความเร็วมอเตอร์ด้านซ้าย +
  RightOutput = RightSpeed - Output;      //ความเร็วมอเตอร์ด้านขวา -

  if (LeftOutput > MaxSpeed) LeftOutput = MaxSpeed;
  if (RightOutput > MaxSpeed) RightOutput = MaxSpeed;
  if (LeftOutput < 0) LeftOutput = 0;     //ถ้าน้อยกว่า 0 ให้มอเตอรซ้ายหยุด
  if (RightOutput < 0) RightOutput = 0;   //ถ้าน้อยกว่า 0 ให้มอเตอรขวาหยุด

  FD2(LeftOutput, RightOutput);   //ส่งให้มอเตอร์เคลื่อนที่ตามมอเตอร์ซ้าย/ มอเตอร์ขวา
  PreError = Error;               //กำหนด Error ปัจจุบันให้เเท่ากับ Error ก่อนหน้านี้
  Integral += Error;              //บวกผลรวมของ Error ไปเรื่อยๆ
}

void TracJC(int MotorSpeed, int Time) {  //แทรกเส้นแบบ PID
  InitialSpeed(MotorSpeed);
  CalError();
  while (Error < 100) {                 //ยังไม่เจอแยก ให้ทำการ TracPID
    // CheckObstacle();                 //เช็คสิ่งกีดขวาง
    TracPID();
    CalError();
  }
  Forward(MotorSpeed, Time);
}

void TracTime(int MotorSpeed, int Time) {   //แทรกเส้น PID แบบหน่วงเวลา
  ResetTimer0();
  InitialSpeed(MotorSpeed);
  while (Timer0 < Time) {                   //ยังไม่ถึงเวลาที่กำหนดให้ทำต่อไป
    CalError();
    TracPID();
    ReadTimer0();
  }
}


void TracPIDBackward()  //เดินตามเส้นถอยหลังแบบ PID
{
  int Output, LeftOutput, RightOutput, KpTemp;
  if (abs(Error) <= 1) KpTemp = 1; else KpTemp = Kp;
  Output = (KpTemp * Error) + (Ki * Integral) + Kd * (Error - PreError);  //สมการ PID
  LeftOutput = LeftSpeed + Output;        //ความเร็วมอเตอร์ด้านซ้าย +
  RightOutput = RightSpeed - Output;      //ความเร็วมอเตอร์ด้านขวา -

  if (LeftOutput > MaxSpeed) LeftOutput = MaxSpeed;
  if (RightOutput > MaxSpeed) RightOutput = MaxSpeed;
  if (LeftOutput < 0) LeftOutput = 0;     //ถ้าน้อยกว่า 0 ให้มอเตอรซ้ายหยุด
  if (RightOutput < 0) RightOutput = 0;   //ถ้าน้อยกว่า 0 ให้มอเตอรขวาหยุด

  BK2(LeftOutput, RightOutput);   //ส่งให้มอเตอร์เคลื่อนที่ตามมอเตอร์ซ้าย/ มอเตอร์ขวา
  PreError = Error;               //กำหนด Error ปัจจุบันให้เเท่ากับ Error ก่อนหน้านี้
  Integral += Error;              //บวกผลรวมของ Error ไปเรื่อยๆ
}

void TracJCBackward(int MotorSpeed, int Time) {  //แทรกเส้นถอยหลังแบบ PID
  InitialSpeed(MotorSpeed);
  CalErrorBack();
  while (Error < 100) {  //ยังไม่เจอแยก
    TracPIDBackward();
    CalErrorBack();
  }
  Backward(MotorSpeed, Time);  //ถอยหลังไปอีกนิดตาม Time
}

void TracBackwardTime(int MotorSpeed, int Time) {   //แทรกเส้น PID แบบหน่วงเวลา
  ResetTimer0();
  InitialSpeed(MotorSpeed);
  while (Timer0 < Time) {                   //ยังไม่ถึงเวลาที่กำหนดให้ทำต่อไป
    CalErrorBack();
    TracPIDBackward();
    ReadTimer0();
  }
}

*/

void TracJCSpeedTime(int MotorSpeed, int Time){
  BaseSpeed = MotorSpeed;
  TracJCStop();
  Forward();
  delay(Time);
  BaseSpeed = Speed;
  InitialSpeed();
}

void TracSpeedTime(int TracSpeed, int TracTime){
  BaseSpeed = TracSpeed;
  InitialSpeed();
  StartTimer();
  CalError();
  while(ReadTomer() < TracTime){
    TracPID();
    delay(Kt);
    
  }
  
}


void TracJCStop() { //เดินถึงเส้นและออกจากฟังก์ชั่น
  InitialSpeed();
  CalError();
  while Error < 99) {
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
  BackwardBalanceF();
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
