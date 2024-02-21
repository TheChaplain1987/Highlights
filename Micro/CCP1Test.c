#include <18f4520.h>
#use delay ( clock = 20000000 )
#fuses HS, NOWDT, NOLVP

#include "../Library/myLibrary.h"

#INT_CCP1
void int_ccp1_isr() {
   *LATC ^= 0x01;           // Demonstration
}

main() {

   *TRISC = 0x04;
   T1CON -> TMR1ON = 1;     // Default PS = 1
   CCP1CON -> CCPxMx = 0x4; // Every falling edge
   PIE1 -> CCP1IE = 1;
   INTCON -> PEIE = 1;
   INTCON -> GIE = 1;
   
   while( 1 ) {
      
   }
}
