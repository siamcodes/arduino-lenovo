int LED[] = {PA1, PA2, PB5, PB6, PC13};

void setup() {
  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(LED[3], OUTPUT);
  pinMode(LED[4], OUTPUT);
}

void loop() {
  for (int i = 0; i <= 4; i++) {
    digitalWrite(LED[i], HIGH);
    delay(100);
    digitalWrite(LED[i], LOW);
    delay(100);
  }

  for (int i = 4; i >= 0; i--) {
    digitalWrite(LED[i], HIGH);
    delay(100);
    digitalWrite(LED[i], LOW);
    delay(100);
  }

}
