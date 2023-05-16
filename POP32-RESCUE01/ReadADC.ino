void ReadADC() {
  L2 = analog(4);
  L1 = analog(3);
  C = analog(2);
  R1 = analog(1);
  R2 = analog(0);

  Dist = analog(8) / 41;
  BL = analog(7);
  BC = analog(6);
  BR = analog(5);
  
}
