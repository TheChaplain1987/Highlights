// This code expects a button on C0 and an LED on C7

#include <18f4520.h>
#use delay ( clock = 20000000 )
#fuses HS, NOWDT, NOLVP

int *TRISC = 0xF94;
int *PORTC = 0xF82;

main() {
   
   *TRISC = 0x01;  // C0 input - All output
   
   while( 1 ) {
      if( *PORTC & 0x01 ) {     // If switch is ON
         *PORTC |= 0x80;   // Turn LED on
      }
      else {
         *PORTC &= ~0x80; // Otherwise turn it off
      }
   }
}

