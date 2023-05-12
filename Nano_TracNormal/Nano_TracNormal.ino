int ML1 = 5;
int ML2 = 6;
int MR1 = 9;
int MR2 = 10;

int Speed = 70;

void setup() {
  pinMode(ML1, OUTPUT);
  pinMode(MR2, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);
  Forward(Speed, 1000);
  MotorStop();
}

void loop() {

}

void Forward(int MotorSpeed, int Time) {
  analogWrite(ML1, 100);
  analogWrite(ML2, 0);
  analogWrite(MR1, 100);
  analogWrite(MR2, 0);
  delay(Time);
}

void MotorStop() {
  analogWrite(ML1, 0);
  analogWrite(ML2, 0);
  analogWrite(MR1, 0);
  analogWrite(MR2, 0);
}
