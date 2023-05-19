#include <POP32.h> //เพิ่มไลบราลี
int L3, L2, L1, C, R1, R2, R3; //ประกาศตัวแปรเซ็นเซอร์หน้า 7 ตัว
int BL2, BL1, BC, BR1, BR2; //ประกาศตัวแปรเซ็นเซอร์หลัง 5 ตัว
int  RefL2 = 2392, RefL1 = 2479, RefC = 2470, RefR1 = 2503, RefR2 = 1821;
int  RefBL1 = 2335, RefBR1 = 2158;
int Speed = 40, SlowSpeed = 30, AccSpeed = 100, TurnSpeed = 60;
int LeftSpeed, RightSpeed, LeftSpeedBack, RightSpeedBack;
int Kp = 10, Ki = 0, Kd = 30, Error, PreError, Integral;
long BaseTimer0, Timer0, BaseTimer1, Timer1;
void setup() {
  beep(0);        //เสียงบี๊บ
  //KickFront();
  //KickBack();
  ShowADC();      //แสดงค่าเซ็นเซอร์
  sw_ok_press();  //รอจนกว่าจะมีการกดปุ่ม sw ok
  beep(0);
  delay(100);
  StartTimer1();
  //Forward(Speed, 1000);
  //Backward(Speed,1000);
  //TurnLeft();
  //TurnRight();
  //ForwardBalance();
  //BackwardBalance();
  //TrackJCBalance(Speed,100);
  //TrackSpeedTimer(AccSpeed,500);
  //Box1();
  //MotorStop();
}

void loop() {
  Box1();
  Finish();
}
