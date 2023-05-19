void Read5Analog()  //อ่านค่าเซ็นเซอร์หน้า 7 ตัว
{
  L2 = analog(4);
  L1 = analog(3);
  C = analog(2);
  R1 = analog(1);
  R2 = analog(0);
}

void Read2AnalogBack()  //อ่านค่าเซ็นเซอร์หลัง 5 ตัว
{
  BL1 = analog(6);
  BR1 = analog(5);
}
