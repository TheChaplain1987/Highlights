#include <ESP8266wifi.h>
#include "AdafruitIO_WiFi.h"
#include "ADS1X15.h"
#include <DHT.h>

// Define ADC addr.
ADS1115 ADS( 0x48 );

// Define DHT11 temperature / humidity sensor
#define DHTPin  D5
#define DHTType DHT11
DHT dht(DHTPin, DHTType);

// Define UV-Lamp
#define lamp D7

// Define water pump
#define pump D4

// Set user WiFi login information
#define WIFI_SSID       "TP-Link_2A0E"
#define WIFI_PASS       "67947799"

// Set user Adafruit IO login information
#define IO_USERNAME     "thechaplain"
#define IO_KEY          "aio_XRfS31LlWHfjKCkAywAWssAqDlgM"

// Connect to the Adafruit IO server
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

// Create feed objects
AdafruitIO_Feed *temperatureFeed = io.feed("Temperature");
AdafruitIO_Feed *humidityFeed = io.feed("Humidity");
AdafruitIO_Feed *lightFeed = io.feed("Light");
AdafruitIO_Feed *moistureFeed = io.feed("Moisture");

void setup() {

  // Begin serial output at 115200 baud rate
  Serial.begin(115200);

  // Set lamp and pump pins as outputs
  pinMode( lamp, OUTPUT );
  pinMode( pump, OUTPUT );

  // Set lamp and pump intial states to off
  digitalWrite( lamp, LOW );
  digitalWrite( pump, LOW );

  // Connect to Adafruit IO
  io.connect();

  // Start ADC and set gain
  ADS.begin( );
  ADS.setGain( 0 );

  // Start DHT11 sensor
  dht.begin();

  // Wait for connection
  while(io.status() < AIO_CONNECTED) 
  {
    Serial.print(".");
    delay(500);
  }
}
 
void loop() {
  io.run( );

  // Read temp / humidity from sensors
  float temperature = ( dht.readTemperature( ) * ( 9 / 5 ) ) + 32;
  Serial.print("Temperature: ");
  Serial.println( temperature );
  float humidity = dht.readHumidity( );
  Serial.print("Humidity: ");
  Serial.println( humidity );

  // Read light / moisture from ADC
  float voltFactor = ADS.toVoltage( 2 );
  int lightRead = ADS.readADC( 1 );
  float light = map( ( lightRead * voltFactor ), 0, 3, 0, 100 );
  Serial.print("Light: ");
  Serial.println( light );
  int moistRead = ADS.readADC( 0 );
  float moisture = map( ( moistRead * voltFactor ), 13.8, 0, 0, 100 );
  Serial.print("Moisture: ");
  Serial.println( moisture );

  // Lamp actions
  if ( light <= 35 ) {
    digitalWrite( lamp, HIGH );
  }
  else {
    digitalWrite( lamp, LOW );
  }

  // Pump actions
  if ( moisture <= 50 ) {
    digitalWrite( pump, HIGH );
    delay( 250 );
    digitalWrite( pump, LOW );
  }
  else {
    digitalWrite( pump, LOW );
  }

  // Save variables to their feeds on Adafruit IO
  temperatureFeed -> save( temperature );
  delay( 200 );
  humidityFeed -> save( humidity );
  delay( 200 );
  lightFeed -> save( light );
  delay( 200 );
  moistureFeed -> save( moisture );

  // Delay for Adafruit IO uploads per minute ( 30/min )
  delay( 8000 );
}
