#include <18f4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "../Library/myLibrary.h"
#include "../Library/modifiedlcd.h"

#INT_RDA
void int_rda_isr(){
    delay_ms(250);                       // Presentation Purposes.
    printf(lcd_putc,"\f Rx: %c",*RCREG);
    *TXREG = *RCREG + 1;
}

main(){
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
  *TXREG = 'A';       // Transmiting 'A'
  while(1){
  }
}


