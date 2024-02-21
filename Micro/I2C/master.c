#include <18f4520.h>
#use delay(clock=20000000)
#fuses HS, NOWDT, NOLVP
#include "../Library/modifiedlcd.h"
#include "../Library/18f4520Library.h"
#define 1 TRUE
#use i2c(MASTER,SDA=PIN_C4,SCL=PIN_C3,SLOW)
main(){
   int i2c_command = 0;
   BYTE address = 0x10;  // Slave address
   lcd_init();
   while(TRUE){
      delay_ms(1000);
      if(i2c_command&0x01){
        address = 0x10;
      }
      else{
        address = 0x20;
      }
      i2c_start();
      i2c_write(address);
      i2c_write(i2c_command);
      i2c_stop();
      printf(lcd_putc,"\f Data %lu", (int16)i2c_command);
      i2c_command++;
   }
}
