// Obstacle Avoidence Robot 
// Motors Test
// Author: J. Martin 4/4/2023

#define leftForward 5    // Motor B pins
#define leftReverse 6  
#define rightForward 9   // Motor A pins
#define rightReverse 10

int speedy = 255;        // Global variable for speed
int turnTime = 500;      // Global varible for turn time

void setup() {
  
  pinMode( leftForward, OUTPUT );
  pinMode( leftReverse, OUTPUT );
  pinMode( rightForward, OUTPUT );
  pinMode( rightReverse, OUTPUT );

  digitalWrite( leftForward, LOW );
  digitalWrite( leftReverse, LOW );
  digitalWrite( rightForward, LOW );
  digitalWrite( rightReverse, LOW );

  Serial.begin( 9600 );
  Serial.println("Starting motor test...");

}

void loop() {
  
  moveForward( speedy );
  delay( 2500 );
  moveReverse( speedy );
  delay( 2500 );
  moveStop( );
  delay( 1000 );
  left90( speedy );
  delay( turnTime );
  moveForward( speedy );
  delay( 2500 );
  right90( speedy );
  delay( turnTime );

}

void moveForward( int x ) {

  analogWrite( leftForward, x );
  analogWrite( leftReverse, 0 );
  analogWrite( rightForward, x );
  analogWrite( rightReverse, 0 );
  
}

void moveReverse( int x ) {

  analogWrite( leftForward, 0 );
  analogWrite( leftReverse, x );
  analogWrite( rightForward, 0 );
  analogWrite( rightReverse, x );
  
}

void moveStop( ) {

  analogWrite( leftForward, 0 );
  analogWrite( leftReverse, 0 );
  analogWrite( rightForward, 0 );
  analogWrite( rightReverse, 0 );
  
}

void left90( int x ) {

  analogWrite( leftForward, 0 );
  analogWrite( leftReverse, x );
  analogWrite( rightForward, x );
  analogWrite( rightReverse, 0 );
  
}

void right90( int x ) {

  analogWrite( leftForward, x );
  analogWrite( leftReverse, 0 );
  analogWrite( rightForward, 0 );
  analogWrite( rightReverse, x );
  
}
