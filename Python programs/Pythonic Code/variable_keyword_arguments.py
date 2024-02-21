# Program that uses variable keyword arguments

# create the function
def full_name( **args ):
    print( args )

# Get user input
first = input('Enter first name: ')
last = input('Enter last name: ')

# Print results
full_name(first = first, last = last)
