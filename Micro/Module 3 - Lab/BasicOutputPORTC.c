#include <18f4520.h>
#use delay( clock = 20000000 )  // Set clock to 20MHz
#fuses HS, NOWDT, NOLVP
#include "../Library/myLibrary.h"

int index = 1;

#INT_EXT
void int_ext_isr() {
   index++;
}

main() {

   // Setting PORTC
   *TRISC = 0x00;          // Make all PORTC output
   
   // Setting PORTB
   ADCON1 -> PCFGx = 15;   // ALL analog
   *TRISB = 0x01;          // Make B0 input 
   INTCON2 -> INTEDG0 = 1; // Trigger on raising edge
   INTCON -> INT0IE = 1;   // Must enable these 3 pins
   INTCON -> PEIE = 1;     // for INTCON to work
   INTCON -> GIE = 1;
   
   while( 1 ) {
   
      switch( index ) {
         case 1:;
            *LATC = 0x1F;
            break;
         case 2:
            *LATC = 0x2F;
            break;
         case 3:
            *LATC = 0x4F;
            break;
         case 4:
            *LATC = 0x8F;
            break;
      }
      
      if( index == 5 ) {
      index = 1;
      }
      
   }
}