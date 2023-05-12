void ConvertADC() //เปลี่ยนจาก analog เป็็น digital (สีดำ=0 สีขาว=1)
{
  ReadADC();  //อ่านค่าสี
  if (FL < RefFL) FL = 0; else FL = 1;
  if (FR < RefFR) FR = 0; else FR = 1;
  if (BL < RefBL) BL = 0; else BL = 1;
  if (BR < RefBR) BR = 0; else BR = 1;
}
