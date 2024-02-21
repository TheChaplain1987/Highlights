# Program to check if two numbers are equal

# Funtion to check if two numbers are equal
# INPUTS  n1 = first number
#         n2 = second number
# OUTPUTS True  = equal
#         False = not equal
def equal( n1, n2 ):
    if n1 == n2:
        return True
    else:
        return False

# User enters two numbers to check     
number1 = int( input('Enter number 1: ') )
number2 = int( input('Enter number 2: ') )

# Print equal or not
if equal( number1, number2 ):
    print(number1, 'and', number2, 'are equal!')
else:
    print(number1, 'and', number2, 'are NOT equal!')
