# Program to print all numbers except multiples of 3

# User enters number
number = int( input('Enter an integer: ') )

# Print all numbers unless its a multiple of 3
for index in range( 1, number + 1 ):
    
    if index % 3 == 0:
        continue
    
    print( index )
