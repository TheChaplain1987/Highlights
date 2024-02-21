#include <18f4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "../Library/myLibrary.h"
#include "../Library/modifiedlcd.h"

main(){
   lcd_init();         // Initialize LCD
   *TRISA = 0x01;
   ADCON1->PCFGx = 0xE;
   ADCON0->ADON = 1;
   ADCON0->CHSx = 0;   // Channel 0
   ADCON1->VCFG0 = 0;  
   ADCON1->VCFG1 = 0;  
   ADCON2->ADFM = 1;   // Right Justified
   ADCON2->ACQTx = 5;
   ADCON2->ADCSx = 5;
   while(1){
      ADCON0->GODONE=1;   // Trigger
      while( ADCON0->GODONE){}
      printf(lcd_putc,"\f Vin=%f V",*Q*(5.0/1023.0));
      delay_ms(500);
   }
}

