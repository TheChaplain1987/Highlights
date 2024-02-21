# Program to calculate fibonacci series

number = int( input('Enter an integer: ') )

t1 = 1
t2 = 1

print( t1 )
for index in range( 1, number ):
    print( t1 )
    
    result = t1 + t2
    
    t2 = t1
    t1 = result