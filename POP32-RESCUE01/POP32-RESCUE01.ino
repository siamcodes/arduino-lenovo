#include <POP32.h>
int L2, L1, C, R1, R2, Dist, BL, BR; //ตัวแแปรเก็บค่าเซนนเซอร์
int RefL2, RefL1, RefC, RefR1, RefR2, RefBL, RefBR; //ตัวแปรเก็บค่าเฉลี่ยเซนนเซอร์
int Speed, ACCSpeed, SlowSpeed, TurnSpeed; //ตัวแแปรความเร็วมอเตอร์
int BaseSpeed, LeftBaseSpeed, RightBaseSpeed, BackLeftBaseSpeed, BackRightBaseSpeed;
long Timer, Timer0, Timer1,  StartTimer0, StartTimer1; //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Kt, KpB, KdB, KiB, KtB, Error, PreError, Integral, SumError, MaxSpeed; //ตัวแปรแกี่ยวกับ PID

void setup() {
  Speed = 50;  //ความเร็วปกติ 70
  ACCSpeed = 100;  //ความเร็วตอนเร่ง 100
  SlowSpeed = 40; //ความเร็วตอนช้า 50
  TurnSpeed = 50;  //ความเร็วตอนเลี้ยว 100
  BaseSpeed = Speed;
  InitialSpeed();  //กำหนดค่าความเร้ว
  InitialADC();  //ใส่ค่าเฉลี่ยของเซนเซอร์สี
  beep(1);        //เสียงบัซเซอร์ 0-3

  //GripDown();     //ยกแขนลง
  //Grip();         //คีบ
  //GripUp();       //ยกแขนขึ้น
  //Put();          //ปล่อย
  //ShowLCD();      //แสดงค่าเริ่มต้น LCD ตอนเปิดเครื่อง
  //delay(500);   //หน่วงเวลา

  ShowADC();     //แสดงค่าที่อ่านจากเซนเซอร์

  sw_ok_press();  //รอจนกว่าจพกดปุ่ม ok
  beep(1);        //เสียงบัซเซอร์ 0-3
  ResetTimer1();
  // ForwardSpeedTime(40, 1500);  //เดินหน้าด้วยความเร็ว 40% เวลา 1500ms
  // BackwardSpeedTime(40, 1500);  //ถอยหลังด้วยความเร็ว 40% เวลา 1500ms
  // TurnLeft();
  // TurnRight();
  // UTurnLeft();
  // UTurnRight();
  // TracJCStop();   ////เดินถึงเส้นและออกจากฟังก์ชั่น (เจอปุ้บแล้วหยุดปับ)
  // TracJC0();    //ใช้ได้ทุกเส้นทุกแยกที่เจอเส้นดำและเขียว ไม่มีการปรับตั้งลำ
  // TracJC1(); ////เดินถึงเส้นจูนขาเข้าและถอยแบบไม่จูน
   TracJC();    ////เดินถึงเส้นที่ไม่ใช่ขอบและถอยแบบจูน ใช้กับรอยต่อระหว่าขาว-ดำ (ตั้งลำตรงที่สุด แต่ใช้ได้บางเส้น)
  // TurnRight();
  // TracJCBlack();
  // BackwardBalance();  //ถอยหลังปรับสมดุล
  // BackwardBalanceF();  //ถอยหลังปรับสมดุลใช้เซ็นเซอร์หน้า
  // ForwardBalanceB();   //เดินหน้าปรับสมดุลใช้เซ็นเซอร์หลัง
  // TracSpeedTime(Speed, 1400);  //แทรก 2 ช่อง หน่วงเวลา
  // TracSpeedTime(ACCSpeed, 600);  //เร่งแต่ละแยก หน่วงเวลา
  // Kick();  //ปล่อยลูกบาศก์
  Finish();
}

void loop() {
  // Can1();
  //Finish();
}
