# Program to check if a number is a perfect square

import math as m

# User enters an integer
number = int( input('Enter an integer: ') )

# Calculate square root
square_root = m.sqrt( number )

# Check remainder
check_remainder = square_root % 1

# Print results
if check_remainder == 0:
    print('Perfect Square')
else:
    print('Not a Perfect Square')
