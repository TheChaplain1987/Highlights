#include <18f4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "../Library/myLibrary.h"
#include "../Library/modifiedlcd.h"

float Vin = 0;
int16 vin_send = 0;

#INT_RDA
void int_rda_isr(){
    printf(lcd_putc,"\f Vin: %f", Vin);
}

#INT_AD
void int_ad_isr() {
   Vin = *Q * (5.0 / 1023.0 );
   vin_send = (Vin * 10.0);
   output_toggle( PIN_C0 );
}

main(){

   // Analog setup
   *TRISA = 0x01;
   ADCON1->PCFGx = 0xE;
   ADCON0->ADON = 1;
   ADCON0->CHSx = 0;   // Channel 0
   ADCON1->VCFG0 = 0;  
   ADCON1->VCFG1 = 0;  
   ADCON2->ADFM = 1;   // Right Justified
   ADCON2->ACQTx = 5;
   ADCON2->ADCSx = 5;
   PIE1 -> ADIE = 1;
   
  *TRISC = 0x80;      // C7 input   

  TXSTA->TXEN=1;      // Transmit Enable
  TXSTA->SYNC=0;      // Asynch Mode

  RCSTA->SPEN=1;      // Serial Enable
  RCSTA->CREN=1;      // Receiver Enable

  TXSTA->BRGH = 0;
  BAUDCON->BRG16 = 0;
  *SPBRG = 31;         // Baud Rate 9.6KHz

  PIE1->RCIE=1;       // Receiver Interrupt Enable INT_RDA
  INTCON->PEIE=1;
  INTCON->GIE=1;

  lcd_init();         // LCD Panel Initialize
  //printf(lcd_putc,"\f Hello");
  while(1){
      ADCON0->GODONE=1;   // Trigger
      delay_ms( 500 );
      printf(lcd_putc,"\f Vin=%f V",*Q*(5.0/1023.0));
      *TXREG = vin_send;       // Transmiting 'Vin'
  }
}


