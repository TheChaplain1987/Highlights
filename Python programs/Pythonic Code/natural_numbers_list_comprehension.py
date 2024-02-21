# Program to list natural numbers using comprehension

# User enters integer
number = int( input('Enter an integer: ') )

# Make list for natural numbers
natNum = [ index for index in range( 1, number + 1 ) ]

# Print natural numbers
print('Natural Numbers:', natNum )
