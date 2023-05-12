#include <analogWrite.h>
int m1 = 27;

void setup() {
  pinMode(m1, OUTPUT);

}

void loop() {
//  digitalWrite(m1, LOW);
//  delay(5000);
//  digitalWrite(m1, HIGH);
//  delay(1000);
  analogWrite(m1, 100);
}
