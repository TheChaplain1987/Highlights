# Program to compute area and perimeter of a square

# Create class
class Square:
    
    def __init__( self, length ):
        self.length = length
        
    def compute_area( self ):
        area = self.length ** 2
        return area
        
    def compute_perimeter( self ):
        perimeter = 4 * self.length
        return perimeter
        
# Get user input
length = int( input('Enter length of sides: ') )

# Create object from user input
object1 = Square( length )

# Compute area
print( f"Area = { object1.compute_area() }" )

# Compute perimeter
print( f"Perimeter = { object1.compute_perimeter() }" )
