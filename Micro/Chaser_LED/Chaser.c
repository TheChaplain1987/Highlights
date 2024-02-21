// Program to make a chaser LED for PIC18F4520

#include <18f4520.h>
#use delay ( clock = 20000000 ) // 20MHz
#fuses HS, NOWDT, NOLVP

int *TRISC = 0xF94;  // Connect registers
int *PORTC = 0xF82;

main() {
   
   *TRISC = 0x00;    // Set all of PORTC as OUTPUT
   *PORTC = 0x00;    // Set all of PORTC to 0V
   
   int mask = 0x01;  // Mask for shifting bits

   while( 1 ) {
   
      // LEDs moving forward
      for( mask = 0x01; mask <= 0x10; mask <<= 1 ) {
         *PORTC |= mask;
         delay_ms( 1000 );
         *PORTC &= ~mask;
      }
      
      // LEDs moving reverse
      for( mask = 0x08; mask >= 0x02; mask >>= 1 ) {
         *PORTC |= mask;
         delay_ms( 1000 );
         *PORTC &= ~mask;
      }
   }
}

