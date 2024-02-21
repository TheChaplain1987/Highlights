# Program to calculate the sum of natural numbers

# User enters number
number = int( input('Please enter a positive integer: ') )

# Start total at 0
sumNatural = 0

# Calculate the sum of natural numbers
for index in range( 1, number + 1 ):
    sumNatural += index

# Print the sum of natural numbers
print('Sum of natural numbers: ', sumNatural )
