void TurnLeft(){
  if(TurnSpeed<=80) Left(TurnSpeed, 25000/TurnSpeed);  // TurnSpeed = 60 ,600RPM
  else Left(TurnSpeed, 20000/TurnSpeed);               // TurnSpeed = 100 , 600RPM
}

void TurnRight(){
  if(TurnSpeed<=80) Right(TurnSpeed, 25000/TurnSpeed);
  else Right(TurnSpeed, 20000/TurnSpeed);
}

void UTurnLeft(){
  if(TurnSpeed<=80) Left(TurnSpeed, 50000/TurnSpeed);
  else Left(TurnSpeed, 40000/TurnSpeed);
}

void UTurnRight(){
  if(TurnSpeed<=80) Right(TurnSpeed, 50000/TurnSpeed);
  else Right(TurnSpeed, 40000/TurnSpeed);
}

void Left(int Speed , int Time){
  SL(Speed);
  delay(Time);
  AO();
}
void Right(int Speed , int Time){
  SR(Speed);
  delay(Time);
  AO();
}

void MotorStop(){ //มอเตอร์หยุด
   AO();  //มอเตอร์หยุดทั้งหมด
   beep();
   delay(10); //หน่วงเวลา 10 ms
}



void Forward() {
  FD2(LeftBaseSpeed, RightBaseSpeed);
}

void Backward() {
  BK2(BackLeftBaseSpeed, BackRightBaseSpeed);
}

void ForwardSpeedTime(int MotorSpeed, int Time) {
  BaseSpeed = MotorSpeed;
  InitialSpeed();
  Forward();
  delay(Time);
  BaseSpeed = Speed;
  InitialSpeed();
}

void BackwardSpeedTime(int MotorSpeed, int Time) {
  BaseSpeed = MotorSpeed;
  InitialSpeed();
  Backward();
  delay(Time);
  BaseSpeed = Speed;
  InitialSpeed();
}
