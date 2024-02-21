#include <18f4520.h>
#use delay( clock = 20000000 )  // Set clock to 20MHz
#fuses HS, NOWDT, NOLVP
#include "../Library/myLibrary.h"

#INT_EXT
void int_ext_isr() {
   *LATB ^= 0x02;
}

main() {

   ADCON1 -> PCFGx = 15; // ALL analog
   *TRISB = 0x01;
   INTCON2 -> INTEDG0 = 1; // Trigger on raising edge
   INTCON -> INT0IE = 1;
   INTCON -> PEIE = 1;
   INTCON -> GIE = 1;
   
   while( 1 ) {
   
   }
}
