// Program to calculate a fibonacci sequence

#include <stdio.h>

int main( void ) {
    int number;
    
    // Set intial terms
    int term1 = 0, term2 = 1;
    int nextTerm = ( term1 + term2 );

    // User enters length of sequence
    printf("Please enter an integer: ");
    scanf(" %d", &number);

    // Print fibonacci sequence
    printf("Fibonacci sequence = %d %d ", term1, term2);
    while ( nextTerm <= number ) {
        printf("%d ", nextTerm);

        // Shift numbers
        term1 = term2;
        term2 = nextTerm;
        nextTerm = ( term1 + term2 );
    }
    printf("\n");

    // Exit program
    return 0;
}
