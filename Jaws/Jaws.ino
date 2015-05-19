#include <Servo.h>

Servo myservo;

void setup() 
{
  myservo.attach(9);
}

void loop() {

 myservo.writeMicroseconds(1400);
 delay(1000);
 
 myservo.writeMicroseconds(1500);
 delay(1000);

}

