void Can1() {
  Forward(Speed, 100);
  TracJC(Speed, 50);
  TurnLeft();
  TracJC(Speed, 50);
  TurnLeft();
  TracJC(Speed, 100);
  TracJC(Speed, 50);
  TurnLeft();
  TracTime(Speed, 2000);
}

void CanNormal() //สนามที่บ้าน
{
  Backward(Speed, 100);           //เดินจากจุดเริ่มต้น 100
  TracNormalBackward(Speed, 40);  //แทรกเดินเตรียมเลี้ยว
  TurnLeft();                     //เลี้ยว
  TracNormalBackward(Speed, 40);  //แทรกเดินเตรียมเลี้ยว
  UTurn();                        //เลี้ยว
  TracNormalBackward(Speed, 100);  //ข้ามแยก
  TracNormalBackward(Speed, 40);  //แทรกเดินเตรียมเลี้ยว
  TurnRight();                    //เลี้ยว

  TracNormalBackwardTime(Speed, 500); //แทรกหน่วงเวลา
}


void CanNormal1() //สนามที่บ้าน
{
  Forward(Speed, 100);           //เดินจากจุดเริ่มต้น 100
  TracNormalJC(Speed, 60);  //แทรกเดินเตรียมเลี้ยว
  TurnLeft();                     //เลี้ยว
  TracNormalJC(Speed, 60);  //แทรกเดินเตรียมเลี้ยว
  UTurn();                        //เลี้ยว
  TracNormalJC(Speed, 200);  //ข้ามแยก
  TracNormalJC(Speed, 60);  //แทรกเดินเตรียมเลี้ยว
  TurnRight();                    //เลี้ยว

  TracNormalTime(Speed, 1000); //แทรกหน่วงเวลา
}
