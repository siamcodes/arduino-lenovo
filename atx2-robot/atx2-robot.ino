#include <ATX2.h>	// ATX2 Board
void setup() {
  XIO();	// ATX2 initialize
  OK();
}

void loop() {
  fd(100);
  delay(2000);
 //  bk(100);
  sleep(2000);
}
