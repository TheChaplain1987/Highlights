# Program to print all factors of an integer

# User enters a number
number = int( input('Enter an integer: ') )

# Print all factors of integer
for index in range( 1, number + 1):
    if number % index == 0:
        print( index )
