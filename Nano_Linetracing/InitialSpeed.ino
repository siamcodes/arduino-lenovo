void InitialSpeed(int MotorSpeed) { //กำหนดความเร็วให้หุ่นยนต์ หลายๆ สเต็ป
  Error = 0 ; //ให้ Error เป็น 0
  PreError = 0;
  Integral = 0;
  Ki = 0;
  MaxSpeed = MotorSpeed;  //ให้ MaxSpeed เท่ากับค่า MotorSpeed ที่กำหนด

  if (MotorSpeed <= 50)
  {
    Kp = 20;            //ทำให้หุ่นยนต์ไม่หลุดเส้น ทางโค้งอาจหลุดเส้น ก็ให้มาเพิ่ม
    Kd = 40;            //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed-5;
  }
  else if (MotorSpeed <= 70)
  {
    Kp = 80;            //ทำให้หุ่นยนต์ไม่หลุดเส้น ทางโค้งอาจหลุดเส้น ก็ให้มาเพิ่ม
    Kd = 120;            //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม   
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed-10;
  }
  else if (MotorSpeed <= 100)
  {
    Kp = 60;                //ทำให้หุ่นยนต์ไม่หลุดเส้น
    Kd = 100;                //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม   
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed-15;
  }
  else if (MotorSpeed <= 150)
  {
    Kp = 60;                //ทำให้หุ่นยนต์ไม่หลุดเส้น
    Kd = 100;                //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม   
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed-20;
  }
   else if (MotorSpeed <= 200)
  {
    Kp = 60;                //ทำให้หุ่นยนต์ไม่หลุดเส้น
    Kd = 100;                //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม   
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed-40;
  }

}
