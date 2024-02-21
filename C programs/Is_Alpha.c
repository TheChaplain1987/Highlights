// Program to check if a symbol is an alphabet

#include <stdio.h>
#include <ctype.h>

int main( void ) {
    int character;

    // User enters symbol to check
    printf("Please enter symbol to check: ");
    // Symbol will store as ASCII number
    scanf(" %d", &character);

    // Check if alphabet using isaplha( int )
    if ( isalpha( character ) ) {
        printf("%d is an alphabet\n", character);
    }
    else {
        printf("%d is NOT an alphabet\n", character);
    }

    // Exit program
    return 0;
}
