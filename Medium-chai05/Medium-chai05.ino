#include <ATX2.h> //เพิ่มไลบราลี
int L3,L2,L1,C,R1,R2,R3;  //ประกาศตัวแปรเซ็นเซอร์หน้า 7 ตัว
int BL2,BL1,BC,BR1,BR2;  //ประกาศตัวแปรเซ็นเซอร์หลัง 5 ตัว
int RefL3=700,RefL2=700,RefL1=700,RefC=700,RefR1=700,RefR2=700,RefR3=700;
int RefBL2=700,RefBL1=700,RefBC=700,RefBR1=700,RefBR2=700;
int RobotSpeed=50,SlowSpeed=40,AccSpeed=100,TurnSpeed=50;
int LeftSpeed,RightSpeed,LeftSpeedBack,RightSpeedBack;
int Kp=10,Ki=0,Kd=30,Error,PreError,Integral;
long BaseTimer0,Timer0;
void setup() {
  // put your setup code here, to run once:
  XIO();  //ประกาศ IO
  beep(0);  //เสียงบี๊บ
  KickFront();
  KickBack();
  ShowAnalog(); //แสดงค่าเซ็นเซอร์
  sw_ok_press();  //รอจนกว่าจะมีการกดปุ่ม sw ok
  beep(0);
  delay(100);
  //Forward(RobotSpeed,2000);
  //Backward(RobotSpeed,2000);
  //TurnLeft();
  //ForwardBalance();
  //TrackJCBalance(RobotSpeed,100);
  //BackwardBalance();
  Box1();
  //TrackSpeedTimer(AccSpeed,500);
  MotorStop();
}

void loop() {
  // put your main code here, to run repeatedly:

}
