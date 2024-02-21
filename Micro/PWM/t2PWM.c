#include <18f4520.h>
#use delay (clock =20000000)
#fuses HS, NOWDT, NOLVP
#include "../Library/myLibrary.h"

main(){
  *TRISC = 0x00;           // CCP1 at C2
  CCP1CON->CCPxMx = 0xC;   // PWM Mode
  *PR2 = 200;              // Tpwm = (PR2+1)
  *CCPR1L = 50;            // 50/100   50% DC
  T2CON->TMR2ON = 1;       //Timer On
  while(1){
  }
}

  
