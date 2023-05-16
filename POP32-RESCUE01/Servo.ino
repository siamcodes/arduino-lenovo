void Kick(){
  MotorStop();
  servo(1,80);
  delay(300);
  servo(1,160);
}
