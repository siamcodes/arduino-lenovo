void Trac(int MotorSpeed) { //เดินตามเส้นธรรมดา
  ConvertADC();
  if (FL == 1 && FR == 1) Forward(MotorSpeed, 1);
  else if (FL == 0) tl(50);
  else if (FR == 0) tr(50);
}

void TracNormalJC(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Forward(MotorSpeed, 1);
  ConvertADC();
  while (FL == 1 || FR == 1) {  //ยังไม่เจอแยก
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


void TracBW(int MotorSpeed) { //เดินตามเส้นธรรมดา
  ConvertADC();
  if (BL == 1 && BR == 1) Backward(MotorSpeed, 1);
  else if (BL == 0) tr(50);
  else if (BR == 0) tl(50);
}

void TracNormalBW(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Backward(MotorSpeed, 1);
  ConvertADC();
  while (BL == 1 || BR == 1) {  //ยังไม่เจอแยก
    TracBW(MotorSpeed);
  }
  Backward(MotorSpeed, Time);  //เดินหน้าไปอีกนิดตาม Time
}
