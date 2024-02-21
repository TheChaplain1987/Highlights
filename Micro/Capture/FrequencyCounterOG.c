#include <18f4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "../../Library/myLibrary.h"
#include "../../Library/modifiedlcd.h"

unsigned int x = 0;
unsigned int16 tstop, tstart, telapsed;

#INT_TIMER1
void int_timer1_isr(){
   x++;                     // Count the overflows
   output_toggle( PIN_C0 );
}

#INT_CCP1
void int_ccp1_isr(){
    tstop = *CCPR1;
    telapsed = x * 0x10000 -tstart + tstop;
    x = 0;   // Rest Overflow
    tstart = tstop;
    output_toggle( PIN_C1 );
}

main(){
   float T1c = 4 * 1 / 20000000.0;
   lcd_init();            // Initializing the LCD Panel
   *TRISC = 0x4;          // 0000 0100   C2 is input
   // Capture System Setup
   CCP1CON->CCPxMx = 0x4; //Capture every falling
   
   // Timer Setup
   T1CON->TMR1ON = 1;     // Timer is ON
   T1CON->TMR1CS = 0;     // Fosc / 4
   T1CON->T1CKPSx = 0;    // PS = 1;
   
   // Interrupt System Setup
   PIE1->TMR1IE = 1;      // Timer 1 overflow interrupt system 0n
   PIE1->CCP1IE = 1;      // CCP1 Interrupt Systen ON
   INTCON->PEIE = 1;
   INTCON->GIE = 1;       // Interrupt System Enabled
   while(1){
         // Just show me the data
         printf(lcd_putc,"\f F = %f", 60 / ( 161 * (T1c * telapsed ) ) );
         delay_ms(100);
   }
}

   
   
