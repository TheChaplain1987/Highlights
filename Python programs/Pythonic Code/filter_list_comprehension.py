# Program to filter a list using comprehension

# Define a list
numbers = [ 12, 17, 28, 19, 11 ]

# Make a new list containing only odd values
odd_numbers = [ index for index in numbers if index % 2 != 0 ]

# Print the new list
print( odd_numbers )
