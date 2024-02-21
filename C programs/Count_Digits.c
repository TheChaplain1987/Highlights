// Program to count the number of digits in an integer number
#include <stdio.h>

int main( void ) {
    int number, num_save, count = 0;

    // User enters integer to be checked
    printf("Please enter an integer: ");
    scanf(" %d", &number);

    // Save original number to print later
    num_save = number;

    // Loop to count digits
    do {
        number /= 10;
        count++;
    } while ( number != 0 );

    // Print number of digits
    printf("Number of digits in %d is %d", num_save, count);

    // Exit program
    return 0;
}
