# Program to merge two dictionaries

# create two dictionaries
A = {12: 'Kathmandu', 11: 'London', 3: 'Sydney'}
B = {10: 'New York', 2: 'Delhi'}

# merge the two dictionaries using update()
C = A.copy()
C.update( B )

# print the merged dictionary
print( C )
