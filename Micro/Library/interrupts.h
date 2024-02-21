// Function to control the external interrupt for B0
// Inputs: x = 1 for raising edge, 0 for falling edge
void ext_int_B0( int x );

void ext_int_B0( int x ) {
   INTCON2 -> INTEDG0 = x;
   INTCON -> INT0IE = 1;
   INTCON -> PEIE = 1;
   INTCON -> GIE = 1;
}

// Function to control the external interrupt for B1
// Inputs: x = 1 for raising edge, 0 for falling edge
void ext_int_B1( int x );

void ext_int_B1( int x ) {
   INTCON2 -> INTEDG1 = x;
   INTCON3 -> INT1IE = 1;
   INTCON -> PEIE = 1;
   INTCON -> GIE = 1;
}

// Function to control the external interrupt for B1
// Inputs: x = 1 for raising edge, 0 for falling edge
void ext_int_B2( int x );

void ext_int_B2( int x ) {
   INTCON2 -> INTEDG2 = x;
   INTCON3 -> INT2IE = 1;
   INTCON -> PEIE = 1;
   INTCON -> GIE = 1;
}
