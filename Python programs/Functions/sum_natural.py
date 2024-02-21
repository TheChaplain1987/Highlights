# Program to calculate the sum of natural numbers using a function

def find_sum( num ):
    total = 0
    
    for index in range( 1, num + 1 ):
        total += index
        
    return total
    
number = int( input('Enter an integer: ') )

print('Sum of natural numbers: ', find_sum( number ) )
