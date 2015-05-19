#include <Servo.h>

Servo servo1;
Servo servo2;

void setup() {
  servo1.attach(8);
  servo2.attach(9);
}


void loop() {
 servo1.writeMicroseconds(1500);
 delay(1000);
 
 servo2.writeMicroseconds(1500);
 delay(1000);
 
 servo1.writeMicroseconds(1400);
 delay(1000);
 
 servo2.writeMicroseconds(1400);
 delay(1000);
}
