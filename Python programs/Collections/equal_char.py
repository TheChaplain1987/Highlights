# Program to check if the first and last of a string are equal

# User enters a string
check = input('Enter a string: ')

# If first and last letter are the same, print equal. Else, print not equal
if check[ 0 ] == check[ -1 ]:
    print('Equal')
else:
    print('Not Equal')
