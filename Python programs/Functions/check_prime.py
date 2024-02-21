# Program to check if a number is prime with a function

# Function to check prime
# INPUT num = the number to be checked
# OUTPUT flag = false is prime, true is not prime
def prime( num ):
    
    flag = False
    
    for index in range( 2, num ):
        if num % index == 0:
            flag = True
            break
        
    return flag

# User enters an integer   
number = int( input('Enter an integer: ') )

# Check if prime
if prime( number ):
    print(number, 'is not prime!')
else:
    print(number, 'is prime!')
