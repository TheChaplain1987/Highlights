#include <18f4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "../Library/myLibrary.h"
#include "../Library/modifiedlcd.h"

// Global variables
float t1c = 4.0 / 20000000.0;
unsigned int realRPM, expectedRPM;
unsigned int16 x = 0;
unsigned int16 tstop, tstart;
unsigned int32 telapsed;

// Timer for capture
#INT_TIMER1
void int_timer1_isr() {
   x++;
}

// Capture ISR (CCP2 on C1)
#INT_CCP2
void int_ccp2_isr() {
   tstop = *CCPR2;
   telapsed = (x * 0x10000) - tstart + tstop;
   tstart = tstop;
   x = 0;
}

// Stop button ISR (B0)
#INT_EXT
void int_ext0_isr() {
   *TRISC ^= 0x04;    // Toggle C2 as input or output to stop PWM
   telapsed = 0;      // Conditions for starting back up...
   *CCPR1L = 50;
}

// USART Receive
#INT_RDA
void int_rda_isr() {
   printf(lcd_putc, "\fERPM = %d", *RCREG);  // Print ERPM from monitor
}

main() {
   
   // Initialize LCD
   lcd_init();
   
   // Setup capture for CCP2 (C1)
   *TRISC = 0x82;            // C1 is input
   CCP2CON -> CCPxMx = 0x4;  // Capture every falling edge
   PIE2 -> CCP2IE = 1;       // CCP2 interrupt is ON
   
   // Setup timer1
   T1CON -> TMR1ON = 1;      // Timer1 is ON
   T1CON -> TMR1CS = 0;      // Fosc / 4
   T1CON -> T1CKPSx = 0;     // PS = 1;
   PIE1 -> TMR1IE = 1;       // Timer1 overflow interrupt is ON
   
   // Setup PWM
   CCP1CON -> CCPxMx = 0xC;
   *PR2 = 126;
   *CCPR1L = 10;
   T2CON -> TMR2ON = 1;
   
   // Setup stop button on B0
   ADCON1 -> PCFGx = 0x0F;   // Digital
   *TRISB = 0x01;            // Pin B0 as input
   INTCON2 -> INTEDG0 = 1;   // Rising edge
   INTCON -> INT0IE = 1;     // INT0 ON
   
   // Setup TX/RX
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
     
     // Receive ERPM from monitor
     expectedRPM = *RCREG;
     
     // Set ERPM to PWM
     *CCPR1L = expectedRPM;
     
     // Calculate real RPM from capture
     realRPM = (int)(60.0 / ( 161.0 * (telapsed * t1c) ));
     
      // Send real RPM to monitor
     *TXREG = realRPM;                                   
     delay_ms( 1000 );
     
     // Control adjustments
     if ( realRPM > expectedRPM ) {
         *CCPR1L -= 1;
     }
     if ( expectedRPM > realRPM ) {
         *CCPR1L += 1;
     }
   }
}

