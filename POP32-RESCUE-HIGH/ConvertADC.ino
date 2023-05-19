void Convert5Analog() //แปลงค่า analog หน้า เป็น digital 0:ดำ,1:ขาว
{
  Read5Analog();
  if(L2<RefL2) L2=0; else L2=1; 
  if(L1<RefL1) L1=0; else L1=1; 
  if(C<RefC) C=0; else C=1; 
  if(R1<RefR1) R1=0; else R1=1; 
  if(R2<RefR2) R2=0; else R2=1; 
}

void Convert2AnalogBack() //แปลงค่า analog หลัง เป็น digital 0:ดำ,1:ขาว
{
  Read2AnalogBack();
  if(BL1<RefBL1) BL1=0; else BL1=1; 
  if(BR1<RefBR1) BR1=0; else BR1=1; 
}
