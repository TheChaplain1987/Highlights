# Program to find the sum of the square root of two numbers using a lambda function

import math as m

# Create lambda function
compute = lambda num1, num2 : m.sqrt( num1 ) + m.sqrt( num2 )

# Get user input
n1 = int( input('Enter number 1: ') )
n2 = int( input('Enter number 2: ') )

# Print result
print( f"Sum of square roots: { compute( n1, n2 ) }" )
