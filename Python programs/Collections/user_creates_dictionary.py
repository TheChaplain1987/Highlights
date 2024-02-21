# Program that allows a user to make a dictionary

dictionary = {}

for i in range( 1, 4 ):
    key = input('Enter key: ')
    value = input('Enter value: ')
    dictionary[key] = value

print(dictionary)