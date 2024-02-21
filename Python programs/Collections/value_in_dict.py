# Program to see if a value exists in a dictionary

# Make a dictionary
myDict = { 'a': 'juice', 'b': 'grill', 'c': 'corn' }

# User enters value to check
checkVal = input('Enter a value: ')

# Create a flag
flag = False

# Check index for value using the flag
for index in myDict:
    if myDict[ index ] == checkVal:
        flag = True
    
# Print result    
if flag:
    print('Value found')
else:
    print('Value not found')
    