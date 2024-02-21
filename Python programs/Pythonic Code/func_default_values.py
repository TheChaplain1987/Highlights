# Program that uses arguments with default values

# Create function
def func( n1 = 10, n2 = 100 ):
    print( n1 )
    print( n2 )
    
# Get user input
entered = int( input('Enter an integer: ') )

# Print results
func( entered )
