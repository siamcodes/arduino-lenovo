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

/*
void TurnLeft() {     //เลี้ยวซ้าย
  MotorStop();
  SL(TurnSpeed);      //หมุนซ้าย
  delay(100);
  ConvertADC();
  while (L1 == 1) {   //ถ้าเจอขาวอยู่ วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void TurnRight() {    //เลี้ยวขวา
  MotorStop();
  SR(TurnSpeed);      //หมุนซ้าย
  delay(100);         //ปรับค่าให้เลี้ยวตรงเส้น
  ConvertADC();
  while (R1 == 1) {   //ถ้าเจอขาวอยู่ วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void UTurn() {        //ขวา
  MotorStop();
  SR(TurnSpeed);      //หมุนขวา
  delay(500);         //ปรับค่าให้เลยแยกตัด เพื่อหมุนกลับ
  ConvertADC();
  while (R2 == 1) {   //ถ้าเจอขาวอยู่ วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}
*/

/*
void Forward(int MotorSpeed, int Time) { //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  FD2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void Backward(int MotorSpeed, int Time){  //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  BK2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}
*/
