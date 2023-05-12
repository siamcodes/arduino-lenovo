void MotorStop(){ //มอเตอร์หยุด
   AO();  //มอเตอร์หยุดทั้งหมด
   beep(3);
   delay(10); //หน่วงเวลา 10 ms
}


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
