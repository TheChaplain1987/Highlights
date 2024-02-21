// Program to calculate the roots of a quadratic equation

#include <stdio.h>
#include <math.h>

int main( void ) {
float a, b, c, discrim, root1, root2, realPart, imagPart;

// User enters equation
printf("Please enter A, B, and C: ");
scanf(" %f %f %f", &a, &b, &c);

printf("%.2f^2 + %.2fx + %.2f\n", a, b, c);

// Calculate discriminant
discrim = pow( b, 2 ) - 4 * a * c;
printf("Discriminant = %.2f\n", discrim);

// Calculate roots
if ( discrim == 0 ) {
    root1 = root2 = ( -b ) / ( 2 * a );
    printf("Root 1 = Root 2 = %.2f\n", root1);
}
else if ( discrim > 0 ) {
    root1 = ( -b + sqrt( discrim ) ) / ( 2 * a );
    root2 = ( -b - sqrt( discrim ) ) / ( 2 * a );
    printf("Root 1 = %.2f\n", root1);
    printf("Root 2 = %.2f\n", root2);
}
else {
    realPart = ( -b / ( 2 * a ) );
    imagPart = ( sqrt( -discrim ) / ( 2 * a ) );
    printf("Root 1 = %.2f + i%.2f\n", realPart, imagPart);
    printf("Root 2 = %.2f - i%.2f\n", realPart, imagPart);
}

// Exit program
return 0;
}
