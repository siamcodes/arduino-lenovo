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
      delay(30);  //ถ้าตั้งลำไม่ตรง ให้ปรับตรงนี้
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
      delay(30);  //ถ้าตั้งลำไม่ตรง ให้ปรับตรงนี้
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
        if (ReadTimer() > 300) {
          AO();
          R1 = 0;
          //delay(30);  //ถ้าตั้งลำไม่ตรง ให้ปรับตรงนี้
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
          //delay(30);  //ถ้าตั้งลำไม่ตรง ให้ปรับตรงนี้
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
