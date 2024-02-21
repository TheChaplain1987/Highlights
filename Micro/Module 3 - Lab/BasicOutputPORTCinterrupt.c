#include <18f4520.h>
#use delay( clock = 20000000 )  // Set clock to 20MHz
#fuses HS, NOWDT, NOLVP
#include "../../Library/myLibrary.h"
#include "../../Library/interrupts.h"

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
   *TRISB = 0x02;          // Make B0 input 
   ext_int_B1( 1 );
   
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
