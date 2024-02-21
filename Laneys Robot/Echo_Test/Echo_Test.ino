// Ultrasonic Sensor Test
// Author: J. Martin 4/8/2023

// Defining trig and echo pins
#define trigPin 11
#define echoPin 12

// Variable for ultrasonic sensor
int distance;

void setup() {

  // Setting ultrasonic pins
  pinMode( trigPin, OUTPUT );
  pinMode( echoPin, INPUT );

  // Begin serial output...
  Serial.begin( 9600 );

}

void loop() {

  distance = readDistance( );
  
  // Prints distance in serial output
  Serial.print("Distance: ");
  Serial.println( distance );

}

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
