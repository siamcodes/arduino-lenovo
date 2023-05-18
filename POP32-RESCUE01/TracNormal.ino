/*
void Trac(int MotorSpeed) { //เดินตามเส้นธรรมดา 7 เซนเซอร์
  ConvertADC();
  if (C == 0) Forward(MotorSpeed, 1);
  else if (L2 == 0) SL(90);
  else if (L1 == 0) SL(70);
  else if (R2 == 0) SR(90);
  else if (R1 == 0) SR(70);
}

void TracNormalJC(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Forward(MotorSpeed, 1);
  ConvertADC();
  while ((L1 == 1) || (R1 == 1)) {  //ยังไม่เจอแยก
    Trac(MotorSpeed);
  }
  Forward(MotorSpeed, Time);  //เดินหน้าไปอีกนิดตาม Time
}

void TracNormalTime(int MotorSpeed, int Time) { //แทรกเส้นธรรมดา แบบหน่วงเวลา
  ResetTimer0();
  Forward(MotorSpeed, 1);
  while (Timer0 < Time) {
    Trac(MotorSpeed);
    ReadTimer0();
  }
}


void TracBackward(int MotorSpeed) { //เดินตามเส้นธรรมดา
  ConvertADC();
  if ( BC == 0) Backward(MotorSpeed, 1);
  else if (BL == 0) SR(50);
  else if (BR == 0) SL(50);
}

void TracNormalBackward(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Backward(MotorSpeed, 1);
  ConvertADC();
  while (BL == 1 || BR == 1) {  //ยังไม่เจอแยก
    TracBackward(MotorSpeed);
  }
  Backward(MotorSpeed, Time);  //เดินหน้าไปอีกนิดตาม Time
}

void TracNormalBackwardTime(int MotorSpeed, int Time) { //แทรกเส้นธรรมดา แบบหน่วงเวลา
  ResetTimer0();
  Backward(MotorSpeed, 1);
  while (Timer0 < Time) {
    TracBackward(MotorSpeed);
    ReadTimer0();
  }
}
*/
