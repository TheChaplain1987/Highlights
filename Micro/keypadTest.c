#include <18F4520.h>
#use delay( clock = 20000000 )
#fuses HS, NOWDT, NOLVP
#include "../Library/myLibrary.h"
#include "../Library/myKeypad.h"
#include "../Library/modifiedLCD.h"

main( void ) {

   char key;
   keyPadSetup();
   lcd_init();
   *TRISC = 0x00;
   
   while( 1 ) {
      key = keyPressService();
      *LATC = key;
      printf(lcd_putc,"\f Key = %c", key);
      delay_ms( 250 );
   }
}

