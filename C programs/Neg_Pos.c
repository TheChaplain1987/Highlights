// Program to check if a number is negative or positive

#include <stdio.h>

int main( void ) {
    int number;

    // User enters number
    printf("Please enter an integer number: ");
    scanf(" %d", &number);

    // Check is number is negative or positive
    if ( number < 0 ) {
        printf("%d is NEGATIVE\n", number);
    }
    else if ( number > 0 ) {
        printf("%d is POSITIVE\n", number);
    }
    else {
        printf("%d is ZERO\n", number);
    }

    // Exit program
    return 0;
}
