#include <18f4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "../Library/myLibrary.h"
#include "../Library/modifiedlcd.h"

// USART Receive
#INT_RDA
void int_rda_isr() {
   printf(lcd_putc, "\fBinary = %d", *RCREG);
}

main() {

   // Initialize LCD
   lcd_init();
   
   // Setup TX/RX
   *TRISC |= 0x80;           // C7 = RX, C6 = TX
   TXSTA -> TXEN = 1;        // Transmit enable
   TXSTA -> SYNC = 0;        // Asynch mode
   RCSTA -> SPEN = 1;        // Serial enable
   RCSTA -> CREN = 1;        // Receiver enable
   TXSTA -> BRGH = 0;
   BAUDCON -> BRG16 = 0;
   *SPBRG = 31;
   PIE1 -> RCIE = 1;         // Receiver interrupt enable
   
   // Global / peripheral enable
   INTCON -> GIE = 1;        // Global
   INTCON -> PEIE = 1;       // Peripheral
   
   while( 1 ) {
   
   }

}
