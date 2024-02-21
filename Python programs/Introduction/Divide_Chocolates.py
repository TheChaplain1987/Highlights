# Program to divide chocolates evenly

# User inputs data
chocolates = int( input('Enter number of chocolates: ') )
children = int( input('Enter number of children: ') )

# Calculate chocolates
distrobution = chocolates // children
left_over = chocolates % children

# Print results
print('Each child gets', distrobution, 'chocolates with', left_over, 'left over')
