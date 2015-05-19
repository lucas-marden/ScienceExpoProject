#include <Servo.h>

Servo servo1;

void setup() {
  servo1.attach(9);
}

void loop() {
  servo1.writeMicroseconds(1500);
  delay(350);

  servo1.writeMicroseconds(1600);
  delay(350);
}
