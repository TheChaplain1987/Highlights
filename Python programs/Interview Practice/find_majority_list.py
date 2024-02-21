# Program to find the majority element of a list

from collections import Counter

# Function to find majority element
def findMajority( lst ):
    
    # Convert list to dict ( elements = keys, occurence = values )
    dictList = Counter( lst )
    
    # Find majority
    for ( key, value ) in dictList.items():
        if value > ( len( lst ) / 2 ):
            print( key )
            return
    print('None')

# Define a list
randomList = [ 1, 7, 8, 7, 7, 7 ]

# Print majority element
findMajority( randomList )
