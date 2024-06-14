void Forward(int MotorSpeed, int Time) {
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  analogWrite(MA1, RightSpeed);
  analogWrite(MA2, 0);
  analogWrite(MB1, LeftSpeed);
  analogWrite(MB2, 0);
  delay(Time);
}

void Backward(int MotorSpeed, int Time) {
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  analogWrite(MA1, 0);
  analogWrite(MA2, RightSpeed);
  analogWrite(MB1, 0);
  analogWrite(MB2, LeftSpeed);
  delay(Time);
}

void MotorStop() {
  analogWrite(MA1, 0);
  analogWrite(MA2, 0);
  analogWrite(MB1, 0);
  analogWrite(MB2, 0);
  delay(10);
}

void TurnLeft() { //เลี้ยวซ้าย
  MotorStop();
  sl(TurnSpeed); //หมุนซ้าย
  delay(200);
 // ConvertADC();
 // while (L2 == 1) { //ถ้าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
 //   ConvertADC();
 // }
  MotorStop();
}

void TurnRight() { //เลี้ยวขวา
  MotorStop();
  sr(TurnSpeed); //หมุนขวา
  delay(200);
 // ConvertADC();
 // while(R2 == 1) { //ถ้าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
 //   ConvertADC();
 // }
  MotorStop();
}

void UTurnRight() { 
  MotorStop();
  sr(TurnSpeed); //หมุนขวา
  delay(400);    //ปรับค่าให้เลยแยกตัด เพื่อหมุนกลับ
  //ConvertADC();
  //while (R2 == 1) { //ถ้าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
  //  ConvertADC();
  //}
  MotorStop();
}

void UTurnLeft() { 
  MotorStop();
  sl(TurnSpeed); //หมุนซ้าย
  delay(400);    //ปรับค่าให้เลยแยกตัด เพื่อหมุนกลับ
  //ConvertADC();
  //while (R2 == 1) { //ถ้าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
  //  ConvertADC();
  //}
  MotorStop();
}

void sl(int MotorSpeed){
  analogWrite(MA1, MotorSpeed);
  analogWrite(MA2, 0);
  analogWrite(MB1, 0);
  analogWrite(MB2, MotorSpeed);
}

void sr(int MotorSpeed){
  analogWrite(MA1, 0);
  analogWrite(MA2, MotorSpeed);
  analogWrite(MB1, MotorSpeed);
  analogWrite(MB2, 0);
}

void tl(int MotorSpeed){
  analogWrite(MA1, MotorSpeed);
  analogWrite(MA2, 0);
  analogWrite(MB1, 0);
  analogWrite(MB2, 0);
}

void tr(int MotorSpeed){
  analogWrite(MA1, 0);
  analogWrite(MA2, 0);
  analogWrite(MB1, MotorSpeed);
  analogWrite(MB2, 0);
}

void fd(int LeftSpeed, int RightSpeed) {
  analogWrite(MA1, RightSpeed);
  analogWrite(MA2, 0);
  analogWrite(MB1, LeftSpeed);
  analogWrite(MB2, 0);
}

void ao() {
  analogWrite(MA1, 0);
  analogWrite(MA2, 0);
  analogWrite(MB1, 0);
  analogWrite(MB2, 0);
  delay(10);
}
