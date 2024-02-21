// This code expects a button on C0 and an LED on C7

#include <18f4520.h>
#use delay ( clock = 20000000 )
#fuses HS, NOWDT, NOLVP

// Hardware connections
int *TRISC = 0xF94;
int *LATC = 0xF8B;
int *PORTC = 0xF82;

main() {

   BYTE x;
   
   *TRISC = 0x01;  // C0 input - All output
   
   while( 1 ) {
      x = *PORTC & 0x01; // Read C0 only
      if( x == 1 ) {     // If switch is ON
         *LATC |= 0x80;   // Turn LED on
      }
      else {
         *LATC &= ~0x80; // Otherwise turn it off
      }
   }
}

