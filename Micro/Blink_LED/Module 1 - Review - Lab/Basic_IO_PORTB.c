// Program to control an LED at PIN_B0 with a button at PIN_B7
// MCU: PIC18F4520
// Author: J. Martin 9/9/2023

#include <18F4520.h>
#use delay( clock = 20000000 ) // set clock to 20MHz
#fuses HS, NOWDT, NOLVP

int *TRISB = 0xF93; // Connect to registers
int *LATB = 0xF8A;
int *PORTB = 0xF81;

struct _adcon1 { // Structure for ADCON1 for PORTB (Hybrid port)
   int PCFGx:4;
   int VCFG0:1;
   int VCFG1:1;
   int unused:2;
};
struct _adcon1 *ADCON1 = 0xFC1; // Connect to ADCON1

int main( void ) {
   
      *TRISB = 0x80; // Make B7 INPUT, all others OUTPUT
      *LATB = 0x00; // Clear all PORTB data latches
      *PORTB = 0x00;
      ADCON1 -> PCFGx = 0x0F;
      
      while( 1 ) {
         if( *PORTB == 0x80 ) {
            *LATB = 0x01;
         }
         else {
            *LATB = 0x00;
         }
         delay_ms( 500 );
      }
}


