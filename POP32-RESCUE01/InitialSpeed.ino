void InitialSpeed() { //กำหนดความเร็วให้หุ่นยนต์ หลายๆ สเต็ป
  MaxSpeed = BaseSpeed;//ให้ MaxSpeed เท่ากับค่า BaseSpeed ที่กำหนด
  //MaxSpeed = BaseSpeed + 18;

  Error = 0 ; //ให้ Error เป็น 0
  PreError = 0;
  SumError = 0;
  Ki = 0;
  KiB = 0;

  if (BaseSpeed <= 40)
  {
    LeftBaseSpeed = BaseSpeed - 0;
    RightBaseSpeed = BaseSpeed - 0;
    BackLeftBaseSpeed = BaseSpeed - 0;
    BackRightBaseSpeed = BaseSpeed - 0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 1;
  }
  else if (BaseSpeed <= 50)
  {
    LeftBaseSpeed = BaseSpeed - 0;
    RightBaseSpeed = BaseSpeed - 0;
    BackLeftBaseSpeed = BaseSpeed - 0;
    BackRightBaseSpeed = BaseSpeed - 0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 10;
  }
  else if (BaseSpeed <= 60)
  {
    LeftBaseSpeed = BaseSpeed - 0;
    RightBaseSpeed = BaseSpeed - 0;
    BackLeftBaseSpeed = BaseSpeed - 0;
    BackRightBaseSpeed = BaseSpeed - 0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 10;
  }
  else if (BaseSpeed <= 70)
  {
    LeftBaseSpeed = BaseSpeed - 4;
    RightBaseSpeed = BaseSpeed - 0;
    BackLeftBaseSpeed = BaseSpeed - 0;
    BackRightBaseSpeed = BaseSpeed - 0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 10;
  }
  else if (BaseSpeed <= 80)
  {
    LeftBaseSpeed = BaseSpeed - 0;
    RightBaseSpeed = BaseSpeed - 0;
    BackLeftBaseSpeed = BaseSpeed - 0;
    BackRightBaseSpeed = BaseSpeed - 0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 10;
  }
  else if (BaseSpeed <= 85)
  {
    LeftBaseSpeed = BaseSpeed - 0;
    RightBaseSpeed = BaseSpeed - 0;
    BackLeftBaseSpeed = BaseSpeed - 0;
    BackRightBaseSpeed = BaseSpeed - 0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 10;
  }
  else if (BaseSpeed <= 90)
  {
    LeftBaseSpeed = BaseSpeed - 0;
    RightBaseSpeed = BaseSpeed - 0;
    BackLeftBaseSpeed = BaseSpeed - 0;
    BackRightBaseSpeed = BaseSpeed - 0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 10;
  }
  else
  {
    LeftBaseSpeed = BaseSpeed - 0;
    RightBaseSpeed = BaseSpeed - 0;
    BackLeftBaseSpeed = BaseSpeed - 0;
    BackRightBaseSpeed = BaseSpeed - 0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 10;
  }
}
