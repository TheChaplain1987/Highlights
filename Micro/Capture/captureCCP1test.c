#include <18f4520.h>
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOLVP
#include "..\..\Library\myLibrary.h"
#include "..\Library\modifiedlcd.h"

int x=0;
#INT_TIMER1    // Overflow
void int_timer1_isr(){
   x++;         // Counting Overflows
}

unsigned int16 t_start, t_stop, delta_t;
#INT_CCP1
void int_ccp1_isr(){
   t_stop = *CCPR1;
   delta_t = (x * 0x10000) - t_start + t_stop;
   t_start = t_stop;
   x=0;
}

main(){
   float T1c = 4 * 1.0 / 20E6;
   lcd_init();
   *TRISC = 0x04;    // C2 input
   CCP1CON->CCPxMx=4;// Every Falling Capture
   PIE1->CCP1IE=1;   // Interrupt Enable
   
   T1CON->TMR1ON=1;  // Timer 1 ON
   PIE1->TMR1IE=1;   // Timer 1 Overflow Interrupt
   
   INTCON->GIE=1;    // General Interrupt
   INTCON->PEIE=1;
   while(1){
       printf(lcd_putc,"\fT=%f\nF=%f", T1c * delta_t, 1.0/(T1c * delta_t));
       delay_ms(400);
   }
}