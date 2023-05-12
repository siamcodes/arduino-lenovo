void Trac(int MotorSpeed) {
  if (C >= 15) Forward(MotorSpeed, 1);  //ไม่เจอวัตถุ
  else if (L < 15) sl(50);   //เจอวัตถุด้านซ้าย
  else if (R < 15) sr(50);   //เจอวัตถุด้านขวา
  attachInterrupt(digitalPinToInterrupt(Encoder_output_A2), EncoderML, RISING);   //Interrupt Motor L (Channel A2)
  attachInterrupt(digitalPinToInterrupt(Encoder_output_A1), EncoderMR, RISING);   //Interrupt Motor R (Channel A1)
}

void TracNormal(int MotorSpeed, int Time) {
  Forward(MotorSpeed, 1);
  while (C >= 15) {  //ยังไม่เจอวัตถุ
    Trac(MotorSpeed);
  }
  Forward(MotorSpeed, Time);  //เดินหน้าไปอีกนิดตาม Time
}


//void TracEncoder() {
//  Forward(Speed, 1000);
//  attachInterrupt(digitalPinToInterrupt(Encoder_output_A2), EncoderML, RISING);   //Interrupt Motor L (Channel A2)
//  attachInterrupt(digitalPinToInterrupt(Encoder_output_A1), EncoderMR, RISING);   //Interrupt Motor R (Channel A1)
//  if(PulseML == 40){
//    
//  }
//}
