void ForwardBalance() //เดินหน้าปรับจูน
{
  int Status=0;
  Forward(SlowSpeed,1);
  while(Status==0)
  {
    Convert7Analog();
    if((L1==0)&&(R1==0)) Status=1;
    else if((L1==0)&&(R1==1)) //เจอดำด้านซ้าย ขาวด้านขวา
    {
      MotorStop();
      TL(SlowSpeed);
      while(R1==1) {Convert7Analog();}
      delay(50);
      Status=1;
    }
    else if((L1==1)&&(R1==0)) //เจอขาวด้านซ้าย ดำด้านขวา
    {
      MotorStop();
      TR(SlowSpeed);
      while(L1==1) {Convert7Analog();}
      delay(50);
      Status=1;
    }
  }
  MotorStop();
}
void BackwardBalance() //ถอยหลังปรับจูน
{
  int Status=0;
  Backward(SlowSpeed,1);
  while(Status==0)
  {
    Convert5AnalogBack();
    if((BL1==0)&&(BR1==0)) Status=1;
    else if((BL1==0)&&(BR1==1)) //เจอดำด้านซ้าย ขาวด้านขวา
    {
      MotorStop();
      //motor(1,SlowSpeed);
      //motor(2,SlowSpeed);
      motor(3,-SlowSpeed);
      motor(4,-SlowSpeed);
      while(BR1==1) {Convert5AnalogBack();}
      delay(50);
      Status=1;
    }
    else if((BL1==1)&&(BR1==0)) //เจอขาวด้านซ้าย ดำด้านขวา
    {
      MotorStop();
      //motor(3,SlowSpeed);
      //motor(4,SlowSpeed);
      motor(1,-SlowSpeed);
      motor(2,-SlowSpeed);
      while(BL1==1) {Convert5AnalogBack();}
      delay(50);
      Status=1;
    }
  }
  MotorStop();
}
