// Program to make a multiplication table

#include <stdio.h>

int main( void ) {
    int number;

    // User enters number
    printf("Please enter an integer: ");
    scanf(" %d", &number);

    // Make multiplication table
    printf("\n-- Multiplication Table--\n");
    for ( int index = 1; index <= 10; index++ ) {
        printf("%d x %d = %d\n", number, index, ( number * index ) );
    }

    // Exit program
    return 0;
}
