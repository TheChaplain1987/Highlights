#include <18f4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "../Library/myLibrary.h"
#include "../Library/modifiedlcd.h"

float ratioed = 0;

#INT_RDA
void int_rda_isr() {
    ratioed = (*RCREG / 10.0);
    printf(lcd_putc,"\f %f %%", (ratioed / 5.0) * 100.0 );
    printf(lcd_putc,"\n Vin= %f", ratioed);
}

main(){
   
  *TRISC = 0x80;      // C7 input   

  TXSTA->TXEN=1;      // Transmit Enable
  TXSTA->SYNC=0;      // Asynch Mode

  RCSTA->SPEN=1;      // Serial Enable
  RCSTA->CREN=1;      // Receiver Enable

  TXSTA->BRGH = 0;
  BAUDCON->BRG16 = 0;
  *SPBRG = 31;

  PIE1->RCIE=1;       // Receiver Interrupt Enable
  INTCON->PEIE=1;
  INTCON->GIE=1;

  lcd_init();         // LCD Panel Initialize
  while(1){
  }
}


