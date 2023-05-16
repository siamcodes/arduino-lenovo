void CalErrorBack() {   //กำรคำนวณ Error
  ConvertADC();    //เปลี่ยนจาก analog เป็น digital (สีดำ=0 สีขาว=1)
  if ( (BL == 1) && (BC == 1) && (BR == 0) ) Error = 2;
  else if ( (BL == 1) && (BC == 0) && (BR == 0) ) Error = 1;
  else if ( (BL == 1) && (BC == 0) && (BR == 1) ) Error = 0;
  else if ( (BL == 0) && (BC == 0) && (BR == 1) ) Error = -1;
  else if ( (BL == 0) && (BC == 1) && (BR == 1) ) Error = -2;
  else if ((BL == 1) && (BC == 1) && (BR == 1)) Error = 99;   //สิ้นสุดทาง
  else if ((BL == 0) && (BC == 0) && (BR == 0)) Error = 100;     //แยก + T
  else if ((BL == 0)  && (BC == 0)) Error = 101;    //แยกซ้าย
  else if ((BR == 0) && (BC == 0)) Error = 102; //แยกขวา
}
