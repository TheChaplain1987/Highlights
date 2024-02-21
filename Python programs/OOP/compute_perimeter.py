# Program to compute perimeter of a triangle

# Create class
class Triangle:
    
    def __init__( self, x, y, z ):
        self.x = x
        self.y = y
        self.z = z
    
    # Calculate perimeter of triangle  
    def get_perimeter( self ):
        perimeter = self.x + self.y + self.z
        return perimeter

# Get user input        
a = int( input('Enter side A: ') )
b = int( input('Enter side B: ') )
c = int( input('Enter side C: ') )

# Create object
triangle = Triangle( a, b, c )

# Print results
print( f"Perimeter: { triangle.get_perimeter() }" )
