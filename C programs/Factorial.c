// Program to calculate the factorial of a number

#include <stdio.h>

int main( void ) {
    int number;
    unsigned long long sum = 1;

    // Users enters number
    // Number cannot be negative or greater than 65
    do {
        printf("Please enter an positive integer number ( 1 - 65 ): ");
        scanf(" %d", &number);
    } while ( number < 0  || number > 65 );

    // Calculate factorial
    for ( int index = 1; index <= number; index++ ) {
        sum *= index;
    }

    // Print factorial
    printf("Factorial of %d = %llu\n", number, sum);

    // Exit program
    return 0;
}
