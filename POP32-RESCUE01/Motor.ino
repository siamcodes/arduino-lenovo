void TurnLeft() {
  if (TurnSpeed <= 80) Left(TurnSpeed, 25000 / TurnSpeed); // TurnSpeed = 60 ,600RPM
  else Left(TurnSpeed, 20000 / TurnSpeed);             // TurnSpeed = 100 , 600RPM
}

void TurnRight() {
  if (TurnSpeed <= 80) Right(TurnSpeed, 25000 / TurnSpeed);
  else Right(TurnSpeed, 20000 / TurnSpeed);
}

void UTurnLeft() {
  if (TurnSpeed <= 80) Left(TurnSpeed, 50000 / TurnSpeed);
  else Left(TurnSpeed, 40000 / TurnSpeed);
}

void UTurnRight() {
  if (TurnSpeed <= 80) Right(TurnSpeed, 50000 / TurnSpeed);
  else Right(TurnSpeed, 40000 / TurnSpeed);
}

void Left(int Speed , int Time) {
  SL(Speed);
  delay(Time);
  AO();
}


void Right(int Speed , int Time) {
  SR(Speed);
  delay(Time);
  AO();
}


void MotorStop() { //มอเตอร์หยุด
  AO();  //มอเตอร์หยุดทั้งหมด
  beep();
  delay(10); //หน่วงเวลา 10 ms
}

void Forward() {
  FD2(LeftBaseSpeed, RightBaseSpeed);
}

void Backward() {
  BK2(BackLeftBaseSpeed, BackRightBaseSpeed);
}

void ForwardSpeedTime(int MotorSpeed, int Time) {
  BaseSpeed = MotorSpeed;
  InitialSpeed();
  Forward();
  delay(Time);
  BaseSpeed = Speed;
  InitialSpeed();
}

void BackwardSpeedTime(int MotorSpeed, int Time) {
  BaseSpeed = MotorSpeed;
  InitialSpeed();
  Backward();
  delay(Time);
  BaseSpeed = Speed;
  InitialSpeed();
}


void BackwardBalance() { //ถอยหลังปรับสมดุล
  int Status = 0;
  BackwardSpeedTime(SlowSpeed, 1);
  while (Status == 0) {
    ConvertADCBack();
    if ((BL == 0) && (BR == 1)) { //เจอดำข้างซ้าย
      Status = 1;
      AO();
      motor(1, SlowSpeed);
      motor(2, SlowSpeed);
      motor(3, -SlowSpeed);
      motor(4, -SlowSpeed);
      while (BR == 1) {
        ConvertADCBack();
      }
      delay(40);  //ถ้าตั้งลำไม่ตรง ให้ปรับตรงนี้
    }
    else if ((BL == 1) && (BR == 0)) { //เจอดำข้างขวา
      Status = 2;
      AO();
      motor(1, -SlowSpeed);
      motor(2, -SlowSpeed);
      motor(3, SlowSpeed);
      motor(4, SlowSpeed);
      while (BL == 1) {
        ConvertADCBack();
      }
      delay(40);  //ถ้าตั้งลำไม่ตรง ให้ปรับตรงนี้
    }
    else if ((BL == 0) && (BR == 0)) { //เจอดำทั้งสองข้าง
      Status = 3;
    }
  }
  MotorStop();
}


void BackwardBalanceF() {  //ถอยหลังปรับสมดุลใช้เซ็นเซอร์หน้า
  int Status = 0;
  BackwardSpeedTime(SlowSpeed, 1);
  while (Status == 0) {
    ConvertADC();
    if ((L1 == 0) && (R1 == 1)) { //เจอดำข้างซ้าย
      Status = 1;
      AO();
      motor(1, SlowSpeed / 2);
      motor(2, SlowSpeed / 2);
      motor(3, -SlowSpeed);
      motor(4, -SlowSpeed);
      StartTimer();
      while (R1 == 1) {
        ConvertADC();
        if (ReadTimer() > 400) {
          AO();
          R1 = 0;
          // delay(30);  //ถ้าตั้งลำไม่ตรง ให้ปรับตรงนี้
        }
      }
    }
    else if ((L1 == 1) && (R1 == 0)) { //เจอดำข้างขวา
      Status = 2;
      AO();
      motor(1, -SlowSpeed);
      motor(2, -SlowSpeed);
      motor(3, SlowSpeed / 2);
      motor(4, SlowSpeed / 2);
      StartTimer();
      while (L1 == 1) {
        ConvertADC();
        if (ReadTimer() > 300) {
          AO();
          L1 = 0;
          // delay(30);  //ถ้าตั้งลำไม่ตรง ให้ปรับตรงนี้
        }
      }
    }
    else if ((L1 == 0) && (R1 == 0)) { //เจอดำทั้งสองข้าง
      Status = 3;
    }
  }
  //MotorStop();
  BackwardSpeedTime(SlowSpeed, 1);
  ConvertADC();
  while (C == 0) {
    ConvertADC();
  }
}


void ForwardBalanceB() {  //เดินหน้าปรับสมดุลใช้เซ็นเซอร์หลัง
  int Status = 0;
  ForwardSpeedTime(SlowSpeed, 1);

  while (Status == 0) {
    ConvertADCBack();
    if ((BL == 0) && (BR == 1)) { //เจอดำข้างซ้าย
      Status = 1;
      AO();
      motor(1, -SlowSpeed / 2);
      motor(2, -SlowSpeed / 2);
      motor(3, SlowSpeed);
      motor(4, SlowSpeed);
      while (BR == 1) {
        ConvertADC();
      }
      delay(20);  //ถ้าตั้งลำไม่ตรง ให้ปรับตรงนี้
    }
    else if ((BL == 1) && (BR == 0)) { //เจอดำข้างขวา
      Status = 2;
      AO();
      motor(1, SlowSpeed);
      motor(2, SlowSpeed);
      motor(3, -SlowSpeed / 2);
      motor(4, -SlowSpeed / 2);
      while (BL == 1) {
        ConvertADC();
      }
      delay(20);  //ถ้าตั้งลำไม่ตรง ให้ปรับตรงนี้
    }
    else if ((BL == 0) && (BR == 0)) { //เจอดำทั้งสองข้าง
      Status = 3;
    }
  }
}


//-------------------
/*
void ForwardBalance() //เดินหน้าปรับจูน
{
  int Status=0;
  ForwardX(SlowSpeed,1);
  while(Status==0)
  {
    ConvertADC();
    if((L1==0)&&(R1==0)) Status=1;
    else if((L1==0)&&(R1==1)) //เจอดำด้านซ้าย ขาวด้านขวา
    {
      MotorStop();
      TL(SlowSpeed);
      while(R1==1) {ConvertADC();}
      delay(50);
      Status=1;
    }
    else if((L1==1)&&(R1==0)) //เจอขาวด้านซ้าย ดำด้านขวา
    {
      MotorStop();
      TR(SlowSpeed);
      while(L1==1) {ConvertADC();}
      delay(50);
      Status=1;
    }
  }
  MotorStop();
}

void BackwardBalance() //ถอยหลังปรับจูน
{
  int Status=0;
  BackwardX(SlowSpeed,1);
  while(Status==0)
  {
    ConvertADCBack();
    if((BL==0)&&(BR==0)) Status=1;
    else if((BL==0)&&(BR==1)) //เจอดำด้านซ้าย ขาวด้านขวา
    {
      MotorStop();
      //motor(1,SlowSpeed);
      //motor(2,SlowSpeed);
      motor(3,-SlowSpeed);
      motor(4,-SlowSpeed);
      while(BR==1) {ConvertADCBack();}
      delay(50);
      Status=1;
    }
    else if((BL==1)&&(BR==0)) //เจอขาวด้านซ้าย ดำด้านขวา
    {
      MotorStop();
      //motor(3,SlowSpeed);
      //motor(4,SlowSpeed);
      motor(1,-SlowSpeed);
      motor(2,-SlowSpeed);
      while(BL==1) {ConvertADCBack();}
      delay(50);
      Status=1;
    }
  }
  MotorStop();
}

*/
