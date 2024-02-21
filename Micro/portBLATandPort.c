// This code expects a button on C0 and an LED on C7

#include <18f4520.h>
#use delay ( clock = 20000000 )
#fuses HS, NOWDT, NOLVP

int *TRISB = 0xF93;
int *LATB = 0xF8A;
int *PORTB = 0xF81;

struct _adcon1 {
   int PCFGx:4;
   int VCFG0:1;
   int VCFG1:1;
   int unused:2;
};
struct _adcon1 *ADCON1 = 0xFC1;

main() {

   ADCON1 -> PCFGx = 15; // All digital (see datasheet)
   
   *TRISB = 0x01;  // C0 input - All output
   
   while( 1 ) {
      if( *PORTB & 0x01 ) {     // If switch is ON
         *LATB |= 0x80;   // Turn LED on
      }
      else {
         *LATB &= ~0x80; // Otherwise turn it off
      }
   }
}

