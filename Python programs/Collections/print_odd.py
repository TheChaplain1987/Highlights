# Program to print the odd items in the list

# Make a list
numbers = [ 1, 2, 3, 4, 5, 6, 7, 8 ]

# Print the odd numbers in the list
for index in numbers:
    if index % 2 != 0:
        print( numbers[ index - 1 ] )
    else:
        continue
