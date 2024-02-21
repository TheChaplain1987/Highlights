#include <18f4520.h>
#use delay( clock = 20000000 )  // Set clock to 20MHz
#fuses HS, NOWDT, NOLVP
#include "../Library/myLibrary.h"
#include "../Library/modifiedlcd.h"


#INT_EXT
void int_ext_isr() {

   if( input( PIN_B4 ) == 1 && input(PIN_B5) == 0 && input(PIN_B6) == 0
      && input(PIN_B7) == 0) {
      *TXREG = 1;
   }
   else if( input( PIN_B4 ) == 0 && input(PIN_B5) == 1 && input(PIN_B6) == 0
      && input(PIN_B7) == 0) {
      *TXREG = 2;
   }
   else if( input( PIN_B4 ) == 1 && input(PIN_B5) == 1 && input(PIN_B6) == 0
      && input(PIN_B7) == 0) {
      *TXREG = 3;
   }
   else if( input( PIN_B4 ) == 0 && input(PIN_B5) == 0 && input(PIN_B6) == 1
      && input(PIN_B7) == 0) {
      *TXREG = 4;
   }
   else if( input( PIN_B4 ) == 1 && input(PIN_B5) == 0 && input(PIN_B6) == 1
      && input(PIN_B7) == 0) {
      *TXREG = 5;
   }
   else if( input( PIN_B4 ) == 0 && input(PIN_B5) == 1 && input(PIN_B6) == 1
      && input(PIN_B7) == 0) {
      *TXREG = 6;
   }
   else if( input( PIN_B4 ) == 1 && input(PIN_B5) == 1 && input(PIN_B6) == 1
      && input(PIN_B7) == 0) {
      *TXREG = 7;
   }
   else if( input( PIN_B4 ) == 0 && input(PIN_B5) == 0 && input(PIN_B6) == 0
      && input(PIN_B7) == 1) {
      *TXREG = 8;
   }
   else if( input( PIN_B4 ) == 1 && input(PIN_B5) == 0 && input(PIN_B6) == 0
      && input(PIN_B7) == 1) {
      *TXREG = 9;
   }
   else if( input( PIN_B4 ) == 0 && input(PIN_B5) == 1 && input(PIN_B6) == 0
      && input(PIN_B7) == 1) {
      *TXREG = 10;
   }
   else if( input( PIN_B4 ) == 1 && input(PIN_B5) == 1 && input(PIN_B6) == 0
      && input(PIN_B7) == 1) {
      *TXREG = 11;
   }
   else if( input( PIN_B4 ) == 0 && input(PIN_B5) == 0 && input(PIN_B6) == 1
      && input(PIN_B7) == 1) {
      *TXREG = 12;
   }
   else if( input( PIN_B4 ) == 1 && input(PIN_B5) == 0 && input(PIN_B6) == 1
      && input(PIN_B7) == 1) {
      *TXREG = 13;
   }
   else if( input( PIN_B4 ) == 0 && input(PIN_B5) == 1 && input(PIN_B6) == 1
      && input(PIN_B7) == 1){
      *TXREG = 14;
   }
   else if( input( PIN_B4 ) == 1 && input(PIN_B5) == 1 && input(PIN_B6) == 1
      && input(PIN_B7) == 1) {
      *TXREG = 15;
   }
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

   ADCON1 -> PCFGx = 15; // ALL analog
   *TRISB = 0x01;
   INTCON2 -> INTEDG0 = 1; // Trigger on raising edge
   INTCON -> INT0IE = 1;
   INTCON -> PEIE = 1;
   INTCON -> GIE = 1;
   
   while( 1 ) {
   }
}
