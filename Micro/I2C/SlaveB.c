#include <18f4520.h>
#use delay(clock=20000000)
#fuses HS, NOWDT, NOLVP
#include "../Library/modifiedlcd.h"
#include "../Library/18f4520Library.h"
#define 1 TRUE
#define 0 FALSE
#use i2c(SLAVE,SDA=PIN_C4,SCL=PIN_C3,SLOW,ADDRESS=0x20)
typedef enum{START, ADDRESS, DATA, READ_COMMAND}I2C_STATE;
I2C_STATE fState; 
BYTE addressA,dataValue;

#INT_SSP
void int_ssp_isr(){
  BYTE incoming;
  output_toggle(PIN_B3);
  if( i2c_poll() == FALSE){
     if( fState == DATA){
        i2c_write(dataValue); // When you want to talk back.
        fState=START;
     }
  }
  else{
     incoming = i2c_read();
     if(fState == START){
        fState = ADDRESS;
     }
     else if (fState == ADDRESS){
        addressA = incoming;
        fState = DATA;
     }
     else if (fState == DATA){
        dataValue = incoming;
        fState = ADDRESS;
     }
  }
}

main(){
 int i;
 ADCON1->PCFGx=0xF;
 set_tris_b(0x00); // Troubleshooting Pruposes.
 set_tris_c(0x18);  // C3 and C4 inputs.
 set_tris_a(0x00);
 output_b(0x00);
 lcd_init();
 fState = ADDRESS;   //CONTROL_READ;
 enable_interrupts(GLOBAL);
 enable_interrupts(INT_SSP);
 printf(lcd_putc,"\f Hello World");
 while(TRUE){
    printf(lcd_putc,"\f Data %lu", (int16)dataValue);
    delay_ms(300);
 }
}

