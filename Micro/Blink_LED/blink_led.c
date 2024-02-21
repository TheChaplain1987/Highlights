#include <18f4520.h>
#use delay ( clock = 20000000 ) // 20MHz
#fuses HS, NOWDT, NOLVP

main() {
   
   set_tris_c( 0x00 );
   
   while( 1 ) {
      output_toggle( PIN_C0 );
      delay_ms( 500 );
      
   }
}
