#include <18f4520.h>
#use delay( clock = 20000000 ) // 20MHz
#fuses HS, NOWDT, NOLVP

main() {
   
   set_tris_c( 0x01 );
   
   while( 1 ) {
      if( input( PIN_C0 ) == 1 ) {
         output_high( PIN_C7 );
      }
      else {
         output_low( PIN_C7 );
      }
   }
}
