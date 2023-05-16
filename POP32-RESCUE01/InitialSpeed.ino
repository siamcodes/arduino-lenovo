void InitialSpeed(int MotorSpeed) { //กำหนดความเร็วให้หุ่นยนต์ หลายๆ สเต็ป
  Error = 0 ; //ให้ Error เป็น 0
  PreError = 0;
  Integral = 0;
  Ki = 0;
  KiB = 0;
  MaxSpeed = MotorSpeed;  //ให้ MaxSpeed เท่ากับค่า MotorSpeed ที่กำหนด

  if (MotorSpeed <= 50)
  {
    Kp = 10;            //ให้หุ่นยนต์ไม่หลุดเส้น ทางโค้งอาจหลุดเส้น ก็ให้มาเพิ่ม
    Kd = 25;            //ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม
    Kt = 10;
    //LeftSpeed = MotorSpeed;
    //RightSpeed = MotorSpeed;
    LeftBaseSpeed = MotorSpeed - 0;
    RightBaseSpeed = MotorSpeed - 0;
    BackLeftBaseSpeed = MotorSpeed - 0;
    BackRightBaseSpeed = MotorSpeed - 0;
  }
  else if (MotorSpeed <= 70)
  {
    Kp = 20;            //ให้หุ่นยนต์ไม่หลุดเส้น ทางโค้งอาจหลุดเส้น ก็ให้มาเพิ่ม
    Kd = 50;            //ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม
    Kt = 20;
    //LeftSpeed = MotorSpeed;
    //RightSpeed = MotorSpeed;
    LeftBaseSpeed = MotorSpeed - 0;
    RightBaseSpeed = MotorSpeed - 0;
    BackLeftBaseSpeed = MotorSpeed - 0;
    BackRightBaseSpeed = MotorSpeed - 0;
  }
  else if (MotorSpeed <= 100)
  {
    Kp = 50;                //ให้หุ่นยนต์ไม่หลุดเส้น
    Kd = 100;                //ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม
    Kt = 50;
    //LeftSpeed = MotorSpeed;
    //RightSpeed = MotorSpeed;
    LeftBaseSpeed = MotorSpeed - 0;
    RightBaseSpeed = MotorSpeed - 0;
    BackLeftBaseSpeed = MotorSpeed - 0;
    BackRightBaseSpeed = MotorSpeed - 0;
  }
}
