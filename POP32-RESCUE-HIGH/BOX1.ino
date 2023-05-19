void Box1() //วางลูกบาศก์ที่ 1
{
  TrackSpeedTimer(SlowSpeed, 150);
  TrackJCBalance(Speed, 100);
  TurnRight();
  BackwardBalance();
  TrackSpeedTimer(SlowSpeed, 150);
  TrackJCBalance(Speed, 100);
  TurnRight();
  BackwardBalance();
  TrackSpeedTimer(SlowSpeed, 150);
  TrackJCBalance(Speed, 100);
  KickFront();
  UTurnRight();
  TrackJCBalance(Speed, 100);
  TurnLeft();
  BackwardBalance();
  TrackJCBalance(Speed, 100);
  TurnLeft();
  BackwardBalance();
  KickFront();
}
