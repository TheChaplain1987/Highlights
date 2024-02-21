// Testing servo motor
// Author: J. Martin 4/5/2023

#include <Servo.h>

// Define the servo
Servo servoHead;

// Global variable for time delay
int wait = 1000;

void setup() {

  // Attach servo
  servoHead.attach( 13 );

  // Start servo facing forward
  servoHead.write( 45 );

}

void loop() {

  servoHead.write( 0 ); // look left
  delay( wait );
  servoHead.write( 180 ); // look right
  delay( wait );
  servoHead.write( 90 ); // look forward
  delay( wait );
  
  
}
