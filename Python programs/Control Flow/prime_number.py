# Program to check if a number is prime of not

# User enters integer
number = int( input('Please enter an integer: ') )

# Make a flag variable
flag = False

# Check if any numbers between 2 and N are divisable
for index in range( 2, number ):
    if (number % index) == 0:
        flag = True
        break

# Print if prime or not 
if flag:
    print('Not a Prime Number')
else:
    print('Prime Number')