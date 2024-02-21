#include <18f4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "../Library/myLibrary.h"
#include "../Library/modifiedlcd.h"

float Vin = 0;
int index = 1;

#INT_EXT
void int_ext0_isr() {
   index++;
}
#INT_AD
void int_ad_isr() {
   Vin = *Q * (5.0 / 1023.0 );
}


main(){
   // Initialize LCD
   lcd_init();
   
   // Analog setup
   *TRISA = 0x01;
   ADCON1 -> PCFGx = 0xE;
   ADCON0 -> ADON = 1;
   ADCON0 -> CHSx = 0;   // Channel 0
   ADCON1 -> VCFG0 = 0;  
   ADCON1 -> VCFG1 = 0;  
   ADCON2 -> ADFM = 1;   // Right Justified
   ADCON2 -> ACQTx = 5;
   ADCON2 -> ADCSx = 5;
   
   // B0 setup
   *TRISB |= 0x01;
   INTCON2 -> INTEDG0 = 1;
   INTCON -> INT0IE = 1;
   
   // Interrupt setup
   PIE1 -> ADIE = 1;
   INTCON -> PEIE = 1;
   INTCON -> GIE = 1;
   
   while(1){
      ADCON0 -> GODONE=1;   // Trigger
      delay_ms( 250 );
      
      switch( index ) {
         case 1:
            *TRISA = 0x01;
            ADCON1 -> PCFGx = 0xE;
            ADCON0 -> CHSx = 0;
            break;
         case 2:
            *TRISA = 0x02;
            ADCON1 -> PCFGx = 0xD;
            ADCON0 -> CHSx = 1;
            break;
      }
      
      if( index > 2 ) {
         index = 1;
      }
    
      printf(lcd_putc,"\fTemp= %f", Vin * 100);    
   }
}

