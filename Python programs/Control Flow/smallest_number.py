# Program to print the smallest of 3 numbers

# Get user input
num1 = int( input('Enter number 1: ') )
num2 = int( input('Enter number 2: ') )
num3 = int( input('Enter numner 3: ') )

# Check which is smallest
if num1 < num2 and num1 < 3:
    print( num1, 'is smallest.' )
elif num2 < num1 and num2 < num3:
    print( num2, 'is smallest.' )
else:
    print( num3, 'is smallest.' )
