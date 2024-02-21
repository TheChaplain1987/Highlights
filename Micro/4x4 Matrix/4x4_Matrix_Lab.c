// Program to control a 4x4 LED matrix

#include <18f4520.h>
#use delay( clock = 20000000 )  // Set clock to 20MHz
#fuses HS, NOWDT, NOLVP

struct myMatrix {
   int ROW:4;
   int COL:4;
};

struct myMatrix *PORTC = 0xF82;
int *TRISC = 0xF94;

main() {

   *TRISC = 0x00;   // Make all of port C OUTPUT
   *PORTC = 0x00;   // Make all of port C 0V
   
   int mask = 0x01; // Mask for shifting bits
   
   while( 1 ) {
      
      // Chaser COL
      for ( mask = 0x01; mask <= 0x08; mask <<= 1 ) {
         PORTC -> ROW = 0xFF;
         PORTC -> COL = mask;
         delay_ms( 500 );
      }
      
      // Chaser ROW
      for ( mask = 0x01; mask <= 0x08; mask <<= 1 ) {
         PORTC -> ROW = mask;
         PORTC -> COL = 0xFF;
         delay_ms( 500 );
      }
      
      // Whatever...
      for ( mask = 0x01; mask <= 0x10; mask <<= 1 ) {
         PORTC -> ROW = mask;
         PORTC -> COL = mask;
         delay_ms( 500 );
      }
   }
}

