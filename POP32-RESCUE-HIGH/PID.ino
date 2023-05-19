void TrackPID(int MotorSpeed) //เคลื่อนที่ตามช่องแบบ PID
{
  int Output,LeftOutput,RightOutput,MaxSpeed=100;
  
  TuneMotor(MotorSpeed);
  Output = (Kp*Error)+(Ki*Integral)+Kd*(Error-PreError);
  LeftOutput = LeftSpeed+Output;
  RightOutput = RightSpeed-Output;
  if(LeftOutput>MaxSpeed) LeftOutput = MaxSpeed;
  if(LeftOutput<-MaxSpeed) LeftOutput = -MaxSpeed; 
  if(RightOutput>MaxSpeed) RightOutput = MaxSpeed;
  if(RightOutput<-MaxSpeed) RightOutput = -MaxSpeed; 
  motor(1,LeftOutput);
  motor(2,LeftOutput);
  motor(3,RightOutput);
  motor(4,RightOutput);
  PreError = Error;
  Integral += Error;
}
void TrackJC(int MotorSpeed,int Time)  //เจอแยกแล้วหยุด
{
  int Status=0;
  Error=0;
  PreError=0;
  Integral=0;
  while(Status==0)
  {
    TrackPID(MotorSpeed);
    CalError();
    if(Error>=100) Status=1;
  }
  MotorStop();
  Backward(MotorSpeed,1);
  delay(Time);
  MotorStop();
}
void TrackJCBalance(int MotorSpeed,int Time)  //เจอแยกแล้วหยุดปรับจูน
{
  int Status=0;
  Error=0;
  PreError=0;
  Integral=0;
  while(Status==0)
  {
    TrackPID(MotorSpeed);
    CalError();
    if(Error>=100) Status=1;
  }
  MotorStop();
  Backward(MotorSpeed,100);
  MotorStop();
  ForwardBalance();
  MotorStop();
  Backward(MotorSpeed,1);
  delay(Time);
  MotorStop();
}
void TrackSpeedTimer(int MotorSpeed,int Time)  //แทกตามเวลาที่กำหนด
{
  int Status=0;
  Error=0;
  PreError=0;
  Integral=0;
  StartTimer0();
  while(Status==0)
  {
    TrackPID(MotorSpeed);
    CalError();
    ReadTimer0();
    if(Timer0>=Time) Status=1;
  }
}
