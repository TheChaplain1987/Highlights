# Program to append user entered integer to a list

# Make list
oddNumbers = [ 1, 3, 5 ]
print('List: ', oddNumbers)

# User enters an integer
num = int( input('Enter an integer: ') )

# Append user input to list
oddNumbers.append( num )

# Print the new list
print('Appended list: ', oddNumbers)
