# Program that creates a class and prints attributes

# Creat a class
class Bicycle:
    
    def __init__( self, gear, speed ):
        self.gear = gear
        self.speed = speed
        
    def print_attributes( self ):
        print( self.gear )
        print( self.speed )
        
# Create object
bicycle1 = Bicycle( 4, 80 )

# Print attributes
bicycle1.print_attributes()
