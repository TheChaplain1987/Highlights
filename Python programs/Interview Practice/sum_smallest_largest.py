# Program to find the sum of the largest and smallest elements in a list

# Function for sum
def findSum( lst ):
    
    small = min( lst )
    large = max( lst )
    
    total = small + large
    
    return total
    
# Define a list
randomList = [ 7, 6, 1, 8, 9 ]

# Print sum of smallest and largest
print( findSum( randomList ) )
