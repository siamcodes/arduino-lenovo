void Box1() {
  ForwardSpeedTime(Speed, 300);
  // TracSpeedTime(ACCSpeed,600);
  TracJC1();
  TurnRight();
  BackwardBalance();
  TracJC1();
  TurnRight();
  BackwardBalance();
  TracJC();

  KickRed();

  UTurnLeft();
  BackwardBalance();
  
  TracJC();
  TurnLeft();
  BackwardBalance();
  TracJC();
  TurnLeft();
  BackwardBalance();
  TracJC1();
  KickYellow();

  TracJCStop();



}
