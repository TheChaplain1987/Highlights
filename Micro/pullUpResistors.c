#include <18F4520.h>
#use delay( clock = 20000000 )
#fuses HS, NOWDT, NOLVP
#include "../../Microcontrollers/Library/myLibrary.h"

int main( void ) {
   
   ADCON1 -> PCFGx = 15; // All digital
   *TRISB = 0xFF;        // All inputs
   INTCON2 -> RBPU = 0;   // Pull ups engaged
   
   while( 1 ) {
   }
}
