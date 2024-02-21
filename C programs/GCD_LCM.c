// Program to calculate the GCD and LCD of two numbers

#include <stdio.h>

int main( void ) {
    int num1, num2, lcm;
    int og_num1, og_num2;

    // User enters two numbers
    printf("Please enter two integers: ");
    scanf(" %d %d", &num1, &num2);

    // make positive if negative
    num1 = ( num1 > 0 ) ? num1 : -num1;
    num2 = ( num2 > 0 ) ? num2 : -num2;

    // Store original numbers for LCM
    og_num1 = num1;
    og_num2 = num2;

    // Calulate GCD
    while( num1 != num2 ) {
        if ( num1 > num2 ) {
            num1 -= num2;
        }
        else {
            num2 -= num1;
        }
    }
    printf("GCD = %d\n", num1);

    // Calculate LCM from GCD
    lcm = ( og_num1 * og_num2 ) / num1;
    printf("LCM = %d\n", lcm);

    // Exit program
    return 0;
}
