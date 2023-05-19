void CalError() //คำนวณ error
{
  Convert5Analog();
  if ( (L2 == 1) && (L1 == 1) && (C == 1) && (R1 == 1) && (R2 == 0)) Error = -1;
  else if ((L2 == 1) && (L1 == 1) && (C == 1) && (R1 == 0) && (R2 == 0)) Error = -2;
  else if ((L2 == 1) && (L1 == 1) && (C == 1) && (R1 == 0) && (R2 == 1)) Error = -3;
  else if ((L2 == 1) && (L1 == 1) && (C == 0) && (R1 == 0) && (R2 == 1)) Error = -4;
  else if ((L2 == 1) && (L1 == 1) && (C == 1) && (R1 == 1) && (R2 == 1)) Error = 0;
  else if ((L2 == 0) && (L1 == 1) && (C == 1) && (R1 == 1) && (R2 == 1)) Error = 1;
  else if ((L2 == 0) && (L1 == 0) && (C == 1) && (R1 == 1) && (R2 == 1)) Error = 2;
  else if ((L2 == 1) && (L1 == 0) && (C == 1) && (R1 == 1) && (R2 == 1)) Error = 3;
  else if ((L2 == 1) && (L1 == 0) && (C == 0) && (R1 == 1) && (R2 == 1)) Error = 4;
  else if (C == 0) Error = 100;
  else if ((L2 == 0) && (L1 == 0) && (C == 0)) Error = 101;
  else if ((C == 0) && (R1 == 0) && (R2 == 0)) Error = 102;
}

void CalErrorBack() //คำนวณ error
{
  Convert2AnalogBack();
  if ((BL1 == 1)&&(BR1 == 0)) Error = -1;
  else if ((BL1 == 1)&&(BR1 == 1)) Error = 0;
  else if ((BL1 == 0)&&(BR1 == 1)) Error = 1;
  else if ((BL1 == 0)&&(BR1 == 0)) Error = 100;
}
