// program to calculate the sum of natural numbers

#include <stdio.h>

int main( void ) {
    int number;
    int sum = 0;

    // User enters number
    printf("Please enter a positive integer number: ");
    scanf(" %d", &number);

    // Calculate sum and print
    for ( int index = 1; index <= number; index++ ) {
        sum += index;
    }

    printf("Sum of natural numbers = %d\n", sum);

    // Exit program
    return 0;
}
