#include <stdio.h>

int main( void ) {
    int year;

    // User enters year
    printf("Please enter a year: ");
    scanf(" %d", &year);

    // Check if / if not a leap year
    if ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ) {
        printf("%d is a leap year\n", year);
    }
    else {
        printf("%d is NOT a leap year\n", year);
    }

    // Exit program
    return 0;
}
