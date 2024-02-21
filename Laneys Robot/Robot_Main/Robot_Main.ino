// Main program for obstacle avoidence robot
// Author: J. Martin

#include <Servo.h>

// DEFINING SERVO
// Define the servo
Servo servoHead;

// Variable for servo time delay
int wait = 1000;

// DEFINING ULTRASONIC SENSOR
// Defining trig and echo pins
#define trigPin 11
#define echoPin 12

// Variables for distance
int distFront;
int distLeft;
int distRight;

// DEFINING MOTORS
// Motor B pins
#define leftForward 5
#define leftReverse 6

// Motor A pins
#define rightForward 9
#define rightReverse 10

// Variables for speed and turning
int speedy = 255;
int turnTime = 500;

void setup() {

  // Attaching servo
  servoHead.attach( 13 );

  // Start servo facing forward
  servoHead.write( 90 );

  // Setting ultrasonic pins
  pinMode( trigPin, OUTPUT );
  pinMode( echoPin, INPUT );

  // Setting motor pins
  pinMode( leftForward, OUTPUT );
  pinMode( leftReverse, OUTPUT );
  pinMode( rightForward, OUTPUT );
  pinMode( rightReverse, OUTPUT );

  // Starting value of motors
  digitalWrite( leftForward, LOW );
  digitalWrite( leftReverse, LOW );
  digitalWrite( rightForward, LOW );
  digitalWrite( rightReverse, LOW );

  // Begin serial output
  Serial.begin( 9600 );
  Serial.println("Here comes the robots...");

}

void loop() {

  // Start moving forward
  moveForward( speedy );
  
  // Read distance
  distFront = readDistance( );
  Serial.print("Front: ");
  Serial.println( distFront );

  // Object detection...
  // If object is less than 4in away, stop, look left, look right
  if ( distFront <= 4 ) {

    // Stop
    moveStop( );
    
    // Look left
    servoHead.write( 0 );
    delay( wait );
    distLeft = readDistance( );
    Serial.print("Left: ");
    Serial.println( distLeft );
    
    // Look right
    servoHead.write( 180 );
    delay( wait );
    distRight = readDistance( );
    Serial.print("Right: ");
    Serial.println( distRight );

    // Deceiding where to turn
    if ( distLeft > distRight ) {
      left90( speedy );
      delay( turnTime );
    }
    else {
      right90( speedy );
      delay( turnTime );
    }
    
  }

  servoHead.write( 90 );

}

// Function for reading the ultrasonic sensor and returning distance
int readDistance( ) {
  long duration;
  int distance;
  
    // Clearing ultrasonic trigger pin
  digitalWrite( trigPin, LOW );
  delayMicroseconds( 2 );

  // Send 10uS pulse
  digitalWrite( trigPin, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( trigPin, LOW );

  // Read 10uS pulse
  duration = pulseIn( echoPin, HIGH );

  // Calculate distance
  distance = ( duration * 0.0133 ) / 2;

  // Return distance
  return distance;
}

// Function for moving forawrd
void moveForward( int x ) {

  analogWrite( leftForward, x );
  analogWrite( leftReverse, 0 );
  analogWrite( rightForward, x );
  analogWrite( rightReverse, 0 );
  
}

// Function for moving reverse
void moveReverse( int x ) {

  analogWrite( leftForward, 0 );
  analogWrite( leftReverse, x );
  analogWrite( rightForward, 0 );
  analogWrite( rightReverse, x );
  
}

// Function for stopping motors
void moveStop( ) {

  analogWrite( leftForward, 0 );
  analogWrite( leftReverse, 0 );
  analogWrite( rightForward, 0 );
  analogWrite( rightReverse, 0 );
  
}

// Function for turning left 90 degrees
void left90( int x ) {

  analogWrite( leftForward, 0 );
  analogWrite( leftReverse, x );
  analogWrite( rightForward, x );
  analogWrite( rightReverse, 0 );
  
}

// Function for turning right 90 degrees
void right90( int x ) {

  analogWrite( leftForward, x );
  analogWrite( leftReverse, 0 );
  analogWrite( rightForward, 0 );
  analogWrite( rightReverse, x );
  
}
