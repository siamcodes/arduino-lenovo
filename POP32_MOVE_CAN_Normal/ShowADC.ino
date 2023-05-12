void ShowADC() {
  ReadADC();     //อ่านค่าเซนนเซอร์
 
  oled.clear();
  oled.text(1, 0, "FL = %d", FL);
  oled.text(2, 0, "FR = %d", FR);
  oled.text(3, 0, "BL = %d", BL);
  oled.text(4, 0, "BR = %d", BR);
  oled.show();
}
