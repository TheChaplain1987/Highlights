// Program to blink an LED connected to C0
// MCU: PIC18F4520
// Author: J. Martin 9/7/2023

#include <18F4520.h>
#use delay( clock = 20000000 )   // Set clock to 20MHz
#fuses HS, NOWDT, NOLVP

int *TRISC = 0xF94;              // Connect to PORTC
int *LATC = 0xF8B;

int main( void ) {

   *TRISC = 0x00;                // Make all PORTC pins OUTPUT
   
   while( 1 ) {                  // Loop forever
      *LATC |= 0x01;             // Turn on C0
   }

}

