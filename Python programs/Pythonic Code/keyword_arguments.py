# Program that uses a function that takes two arguments and calls with keyword arguments

# Create the function
def print_numbers( arg1, arg2 ):
    print( arg1 )
    print( arg2 )
    
# Get user input
n1 = int( input('Enter number 1: ') )
n2 = int( input('Enter number 2: ') )

# Print using keyword arguments
print_numbers( arg1 = n1, arg2 = n2 )
