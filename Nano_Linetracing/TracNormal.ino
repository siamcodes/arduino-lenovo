void Trac(int MotorSpeed) { //เดินตามเส้นธรรมดา
  ConvertADC();
  if (C == 0) Forward(MotorSpeed, 1);
  else if (L2 == 0) tl(50);
  else if (L1 == 0) tl(30);
  else if (R2 == 0) tr(50);
  else if (R1 == 0) tr(30);
}

void TracNormalJC(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Forward(MotorSpeed, Time);
  ConvertADC();
  while (L2 == 1  || R2 == 1) { //ยังไม่เจอแยก
  //CheckObstacle();            //เช็คสิ่งกีดขวาง
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
