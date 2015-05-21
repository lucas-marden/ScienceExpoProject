#include <Servo.h>

Servo myservo;

void setup()
{
  myservo.attach(9);
}

void loop() {
  for (int i = 0; i < 1000; i - 15);
  myservo.writeMicroseconds(1400);
  delay(i);

  myservo.writeMicroseconds(1500);
  delay(i);

}

