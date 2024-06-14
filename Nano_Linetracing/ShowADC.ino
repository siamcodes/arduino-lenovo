void ShowADC(){
  ReadADC();
  Serial.println(String(L2)+"\t"+String(L1)+"\t"+String(C)+"\t"+String(R1)+"\t"+String(R2));
  delay(200);
}
