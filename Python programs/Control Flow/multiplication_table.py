# Program to create a multiplication table to 10

# User enters number to multiply
number = int( input('Enter number to multiply: ') )

# Print multiplication table
print('Multiplication table...')
for index in range( 1, 10 + 1 ):
    sum = number * index
    print(number, 'x', index, '=', sum)
