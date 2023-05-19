void Box1() //วางลูกบาศก์ที่ 1
{
  TrackSpeedTimer(AccSpeed,600);
  TrackJCBalance(RobotSpeed,100);
  TurnRight();
  BackwardBalance();
  TrackSpeedTimer(AccSpeed,400);
  TrackJCBalance(RobotSpeed,100);
  TurnRight();
  BackwardBalance();
  TrackSpeedTimer(AccSpeed,200);
  TrackJCBalance(RobotSpeed,100);
  KickFront();
}
