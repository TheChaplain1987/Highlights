#include <18F4520.h>
#use delay( clock = 20000000 )
#fuses HS, NOWDT, NOLVP
#include "../../Library/myLibrary.h"
#include "../../Library/ledMatrixPortB.h"

int main( void ) {
   
   BYTE x = 1;
   
   *TRISC = 0x00;
   
   while( 1 ) {
      if( x <= 4 ) {
         light_column_number( x );
         delay_ms( 200 );
         x++;
      }
      else {
         x = 1;
      }
   }
}

