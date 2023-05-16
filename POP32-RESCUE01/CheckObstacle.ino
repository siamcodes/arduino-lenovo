void CheckObstacle() {  //ฟังก์ชั่นเช็คสิ่งกีดขวาง
  ConvertADC();
  if (Dist <= 30) {
    MotorStop();
    SR(45);     //หมุนขวา
    delay(200);
    FD2(25, 65);
    delay(1200);
    // SL(20);
    // delay(150);
    // FD2(30);
    while (L2 == 1) {
      ConvertADC();
    }
  }
}
