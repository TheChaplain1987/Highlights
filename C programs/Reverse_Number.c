// Program to reverse a number
#include <stdio.h>

int main( void ) {
    int number, num_save, remainder;
    int reverse = 0;

    // User enters a number
    printf("Please enter an integer number: ");
    scanf(" %d", &number);

    // Store number to print later
    num_save = number;

    // Reverse number
    do {
        remainder = number % 10;
        reverse = ( reverse * 10 ) + remainder;
        number /= 10;
    } while ( number != 0 );

    // Print resaults
    printf("%d reversed is %d\n", num_save, reverse);

    // Exit program
    return 0;
}
