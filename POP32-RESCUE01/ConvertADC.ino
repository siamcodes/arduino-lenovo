void ConvertADC() { //เปลี่ยนจาก analog เป็น digital (สีดำ=0 สีขาว=1)
  ReadADC();  //อ่านค่าสี
  if (L2 < RefL2) L2 = 0; else L2 = 1;
  if (L1 < RefL1) L1 = 0; else L1 = 1;
  if (C < RefC) C = 0; else C = 1;
  if (R1 < RefR1) R1 = 0; else R1 = 1;
  if (R2 < RefR2) R2 = 0; else R2 = 1;
}

void ConvertADCBack() {
  ReadADC();  //อ่านค่าสี
  if (BL < RefBL) BL = 0; else BL = 1;
  if (BC < RefBC) BC = 0; else BC = 1;
  if (BR < RefBR) BR = 0; else BR = 1;
}
