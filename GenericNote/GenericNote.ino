#include <Servo.h>
//look at me dad!! Reverting Files!
#define NOTES_MAX 4
String NOTES[NOTES_MAX] = { "A", "B", "C", "D" };

int moveTime = 600; // Milliseconds

int measureSeconds = 2000; // Milliseconds

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
 for(int i=0; i<NOTES_MAX; i++) {
    String theNote = NOTES[i];
    int servo1Position = SERVO1_REST;
    int servo2Position = SERVO2_REST;
    // int restTime = 0;

    if(theNote == "A") {
      servo1Position = SERVO1_LEFT;
    } else if(theNote == "B") {
      servo1Position = SERVO1_RIGHT;
    } else if(theNote == "C") {
      servo2Position = SERVO2_LEFT;
    } else if(theNote == "D") {
      servo2Position = SERVO2_RIGHT;
    //} else if(theNote == "ER") {
    //  restTime = measureSeconds/8 - moveTime;
    //} else if(theNote == "QR") {
    //  restTime = measureSeconds/4 - moveTime;
    //} else if(theNote == "HR") {
    //  restTime = measureSeconds/2 - moveTime;
    //} else if(theNote == "WR") {
    //  restTime = measureSeconds - moveTime;
    } else {
      // System.out.println("I don't know what to do with a note called " + theNote);
    }

    Serial.print("Moving servo1 to ");
    Serial.println(servo1Position);
    servo1.writeMicroseconds(servo1Position);

    Serial.print("Moving servo2 to ");
    Serial.println(servo2Position);
    servo2.writeMicroseconds(servo2Position);

    //if(restTime == 0) { // This is real note
      Serial.print("Sent servo location commands, sleep for ");
      Serial.print(moveTime);
      Serial.println(" milliseconds to wait for servos to arrive at location");
      delay(moveTime);
      
      if(servo1Position != SERVO1_REST) {
        Serial.print("Returning servo1 to home position of ");
        Serial.println(SERVO1_REST);
        servo1.writeMicroseconds(SERVO1_REST);
      }

      if(servo2Position != SERVO2_REST) {
        Serial.print("Returning servo2 to home position of ");
        Serial.println(SERVO2_REST);
        servo2.writeMicroseconds(SERVO2_REST);
      }

    //} else { // This is a rest
    //  System.out.println("Sleeping " + restTime + " milliseconds");
    //}
  }
}

