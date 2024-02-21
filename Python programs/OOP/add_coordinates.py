# Program to add coordinates

# Create class
class Coordinate:
    
    def __init__( self, x, y ):
        self.x = x
        self.y = y
        
    def add_coordinates( self, num ):
        x = self.x + num.x
        y = self.y + num.y
        return Coordinate( x, y )

# Create objects       
c1 = Coordinate( 4, 7 )
c2 = Coordinate( 6, 10 )

# Calculate new coordinates
c3 = c1.add_coordinates( c2 )

# Print new coordinates
print( c3.x )
print( c3.y )
