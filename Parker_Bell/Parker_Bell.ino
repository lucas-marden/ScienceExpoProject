#include <Servo.h>

#define NOTES_MAX 17
String NOTES[NOTES_MAX] = { "HIGH", "ER", "MEDIUM-LOW", "ER", "MEDIUM-HIGH", "ER", "LOW", "ER", "QR", "LOW", "ER", "MEDIUM-HIGH", "ER", "HIGH", "ER", "MEDIUM-LOW", "WR",};

int moveTime = 400; // Milliseconds

int measureSeconds = 4000; // Milliseconds

int SERVO1_LEFT = 1400;
int SERVO1_RIGHT = 1500;
int SERVO1_REST = 1450;

int SERVO2_LEFT = 1400;
int SERVO2_RIGHT = 1500;
int SERVO2_REST = 1450;

Servo servo1;
Servo servo2;

void setup()
{
  servo1.attach(8);
  servo2.attach(9);
  Serial.begin(9600);
  Serial.println("Online!");
}

void loop() {
  for (int i = 0; i < NOTES_MAX; i++) {
    // This is what note we will play during this part of the for() loop
    String theNote = NOTES[i];
    Serial.println("I am going to play " + theNote);

    // Now we are going to determine where servo1 and servo2 should go
    int servo1Position = SERVO1_REST;
    int servo2Position = SERVO2_REST;
    int restTime = 0;

    if (theNote == "HIGH") {
      servo1Position = SERVO1_LEFT;
    } else if (theNote == "MEDIUM-HIGH") {
      servo1Position = SERVO1_RIGHT;
    } else if (theNote == "MEDIUM-LOW") {
      servo2Position = SERVO2_LEFT;
    } else if (theNote == "LOW") {
      servo2Position = SERVO2_RIGHT;
    }
    else if (theNote == "ER") {
      restTime = measureSeconds / 8;
    } else if (theNote == "QR") {
      restTime = measureSeconds / 4;
    } else if (theNote == "HR") {
      restTime = measureSeconds / 2;
    } else if (theNote == "WR") {
      restTime = measureSeconds;
    }

    // Now we are going to use that information to
    // move the servos
    Serial.print("Moving servo1 to ");
    Serial.println(servo1Position);
    servo1.writeMicroseconds(servo1Position);

    Serial.print("Moving servo2 to ");
    Serial.println(servo2Position);
    servo2.writeMicroseconds(servo2Position);

    if (restTime == 0) { // This is real note
      Serial.print("Sent servo location commands, sleep for ");
      Serial.print(moveTime);
      Serial.println(" milliseconds to wait for servos to arrive at location");
      delay(moveTime);

      if (servo1Position != SERVO1_REST) {
        Serial.println("Moving servo1 to rest position");
        servo1.writeMicroseconds(SERVO1_REST);
      }

      if (servo2Position != SERVO2_REST) {
        Serial.println("Moving servo2 to rest position");
        servo2.writeMicroseconds(SERVO2_REST);
      }
    } else { // This is a rest
      if (restTime > moveTime) {
        delay(restTime - moveTime);
      }
    }
  }
}
