# Program that uses exception handling with lists

try:
    
    cars = [ 'BMW', 'Ferrari', 'Audi', 'Tesla']
    
    indexCheck = int( input('Enter a car index ( 0 - 2 ): ') )
    
    print( cars[ indexCheck ] )
    
except:
    
    print('Wrong Index')
    