#include <Servo.h>

#define NOTES_MAX 30
String NOTES[NOTES_MAX] = { "D", "QR", "G#", "QR", "Bb", "QR", "HR",  "D", "QR", "C", "QR", "Bb", "QR", "HR", "Bb","Bb","Bb","Bb", "C", "C", "C", "C", "D", "QR", "C", "QR", "Bb"};

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

    if(theNote == "D") {
      servo1Position = SERVO1_LEFT;
    } else if(theNote == "C") {
      servo1Position = SERVO1_RIGHT;
    } else if(theNote == "Bb") {
      servo2Position = SERVO2_LEFT;
    }
     //else if(theNote == "ER") {
     // delay(measureSeconds/8 - moveTime);
     else if(theNote == "QR") {
      delay(measureSeconds/4 - moveTime);
    } else if(theNote == "HR") {
      delay(measureSeconds/2 - moveTime);
    } else if(theNote == "WR") {
      delay(measureSeconds - moveTime);
    }
    


    //if(restTime == 0) { // This is real note
      Serial.print("Sent servo location commands, sleep for ");
      Serial.print(moveTime);
      Serial.println(" milliseconds to wait for servos to arrive at location");
      delay(moveTime);
      
      if(servo1Position != SERVO1_REST) {
        
        servo1.writeMicroseconds(SERVO1_REST);
      }

      if(servo2Position != SERVO2_REST) {
        
        servo2.writeMicroseconds(SERVO2_REST);
      
      }
    }
 }



