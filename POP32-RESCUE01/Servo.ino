void Kick(){
  MotorStop();
  servo(1,0);
  delay(300);
  servo(1,90);
}


void KickRed() 
{
  AO();
  servo(1,0);
  delay(300); 
}

void KickYellow() 
{
  AO();
  servo(1,180);
  delay(300); 
}

void KickBlue() 
{
  AO();
  servo(3,160);
  delay(300);
}

void KickGreen() 
{
  AO();
  servo(4,160);
  delay(300);
}
void CloseServo()
{
  servo(1,90); 
  servo(2,90); 
  servo(3,90); 
  servo(4,90); 
}
void FlagUp() 
{
  MotorStop();
  servo(5,170);
}
void FlagDown() 
{
  MotorStop();
  servo(5,70);
}
