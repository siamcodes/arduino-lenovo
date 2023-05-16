void ShowLCD(){
  oled.clear();  //เคลียร์หน้าจอ
  oled.text(0,0, "ROBO RESCUE 2023"); //แสดงข้อความแถว คอลัมน์
  oled.text(1,0,"Design by Mark");
  oled.show();
}
