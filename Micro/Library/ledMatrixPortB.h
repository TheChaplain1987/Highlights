struct myMatrix {
   int ROWS:4;
   int COLs:4;
};
struct myMatrix *MATRIX = 0xF82;

// Declarations and prototype
void light_column_number( int x );

// Definitions
void light_column_number( int x ) {
   if( x >= 1 && x <= 3 ) {
      MATRIX -> ROWS = 0xF;
      MATRIX -> COLS = x;
   }
}

