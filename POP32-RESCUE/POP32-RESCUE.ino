#include <POP32.h>
int L2, L1, C, R1, R2, Dist, BL, BC, BR; //ตัวแแปรเก็บค่าเซนนเซอร์
int RefL2, RefL1, RefC, RefR1, RefR2, RefBL, RefBC, RefBR; //ตัวแปรเก็บค่าเฉลี่ยเซนนเซอร์
int Speed, ACCSpeed, SlowSpeed, TurnSpeed, LeftSpeed, RightSpeed; //ตัวแแปรความเร็วมอเตอร์
long Timer0, StartTimer0, Timer1, StartTimer1;   //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรแกี่ยวกับ PID


void setup() {
  Speed = 20;  //ความเร็วปกติ 70
  ACCSpeed = 100;  //ความเร็วตอนเร่ง 100
  SlowSpeed = 40; //ความเร็วตอนช้า 50
  TurnSpeed = 70;  //ความเร็วตอนเลี้ยว 70
  beep(1);        //เสียงบัซเซอร์ 0-3

  //GripDown();     //ยกแขนลง
  //Grip();         //คีบ
  //GripUp();       //ยกแขนขึ้น
  //Put();          //ปล่อย
  //ShowLCD();      //แสดงค่าเริ่มต้น LCD ตอนเปิดเครื่อง
  //delay(500);   //หน่วงเวลา

  ShowADC();     //แสดงค่าที่อ่านจากเซนเซอร์
  InitialADC();  //ใส่ค่าเฉลี่ยของเซนเซอร์สี
  sw_ok_press();  //รอจนกว่าจพกดปุ่ม ok
  beep(1);        //เสียงบัซเซอร์ 0-3
  // Forward(Speed, 1000); //เดินหน้าหน่วงเวลา วิ่งที่ 50% เป็นนเวลา 2 วินาที
  // TurnLeft();
  // TurnRight();
  // UTurn();
  // MotorStop();
  ResetTimer1();
}

void loop() {
   CanNormal1();
  // Can1();
   Finish();
}
