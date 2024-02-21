#include <18f4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "../Library/myLibrary.h"
#include "../Library/modifiedlcd.h"

float Vin = 0;
unsigned int x = 0;

#INT_AD
void int_ad_isr() {
   Vin = *Q * (5.0 / 1023.0 );
   output_toggle(PIN_C1);
}

#INT_TIMER1
void int_timer1_isr() {
   *LATC ^= 0x01;
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
   
   // Timer 1 setup
   *TRISC = 0x00;
   T1CON -> TMR1ON = 1;
   T1CON -> TMR1CS = 1;
   T1CON -> T1OSCEN = 1;
   T1CON -> T1CKPSx = 0;
   // T1CON -> T1RUN = 1;
   PIE1 -> TMR1IE = 1;
   
   // Interrupt setup
   PIE1 -> ADIE = 1;
   INTCON -> PEIE = 1;
   INTCON -> GIE = 1;
   
   while(1){
      ADCON0->GODONE=1;   // Trigger
      delay_ms( 250 );
      
      if( Vin > 3.18 && Vin < 3.20 ) {
         printf(lcd_putc,"\fSW1");
      }
      else if( Vin > 2.80 && Vin < 2.90 ) {
         printf(lcd_putc,"\fSW2");
      }
      else if( Vin > 2.30 && Vin < 2.40 ) {
         printf(lcd_putc,"\fSW3");
      }
      else if( Vin > 1.50 && Vin < 1.60 ) {
         printf(lcd_putc,"\fSW4");
      }
      else {
         printf(lcd_putc,"\fPulsar un boton");
      }
   }
}

