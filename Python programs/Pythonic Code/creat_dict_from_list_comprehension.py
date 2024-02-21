# Program to create a dictionary from a list using comprehension

# Define a list
numbers = [1, 2, 3, 4]

# create the dictionary using comprehension
myDict = { numbers: numbers + 1 for numbers in numbers }

# print the dictionary
print( myDict )
