// This API interfaces a keypad to PORTB and services
// a single button press. No multipress is supported.

struct myKeypad {
   int free:1;
   int COLS:3;
   int ROWS:4;
};
struct myKeypad *KEYPAD = 0xF81; // PORTB

// Hardware connection and actions
// Defines do not occupy memory spaces
#define COL1 0x6
#define COL2 0x5
#define COL3 0x3

#define NOPRESS 0xF
#define ROW1 0xE
#define ROW2 0xD
#define ROW3 0xB
#define ROW4 0x7

// Make sure to include your library before myKeypad.h
// You MUST exucute keyPadSetup() before attempting to use the keyboard
void keyPadSetup() {
   ADCON1 -> PCFGx = 15;
   *TRISB = 0xF0;
   INTCON2 -> RBPU = 0;
}

// Service the keypad
char keyPressService() {
   char key = '@'; // Default value.
   KEYPAD -> COLS = COL1; // Service COL1
   switch( KEYPAD -> ROWS ) {
      case ROW1:
         key = '1';
         break;
      case ROW2:
         key = '4';
         break;
      case ROW3:
         key = '7';
         break;
      case ROW4:
         key = '*';
         break;
      default:
   }
   
   KEYPAD -> COLS = COL2; // Service COL2
   switch( KEYPAD -> ROWS ) {
      case ROW1:
         key = '2';
         break;
      case ROW2:
         key = '5';
         break;
      case ROW3:
         key = '8';
         break;
      case ROW4:
         key = '0';
         break;
      default:
   }
   
   KEYPAD -> COLS = COL3; // Service COL3
   switch( KEYPAD -> ROWS ) {
      case ROW1:
         key = '3';
         break;
      case ROW2:
         key = '6';
         break;
      case ROW3:
         key = '9';
         break;
      case ROW4:
         key = '#';
         break;
      default:
   }
   return( key );
}