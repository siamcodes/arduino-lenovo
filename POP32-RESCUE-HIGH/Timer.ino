void StartTimer0()  //เริ่มจับเวลา Timer0
{
  BaseTimer0 = millis();  //อ่านเวลาปัจจุบันในหน่วง ms
  Timer0 = 0;
}
void ReadTimer0() //อ่านค่า Timer 0
{
  Timer0 = millis() - BaseTimer0;
}

void StartTimer1() { //เริ่มใช้งาน Timer1
  BaseTimer1 = millis();  //เก็บเวลาเริมต้นนใน StartTimer1
  Timer1 = 0;   //เคลียร์ Timer1
}

void ReadTimer1(){  //อ่านค่า Timer0
  Timer1 = millis() - BaseTimer1;  //เอาเวลาปัจจุบัน - เวลาเริ่มต้น
}
