# Program to calculate the cube of a number using a lambda function

# Lambda function
cubed = lambda n: n**3

# Get user input
number = int( input('Enter an integer: ') )

# Calculate and print cubed number
print( f"{ number } cubed is { cubed( number )}" )
