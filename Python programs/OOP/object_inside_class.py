# Program that creates an object of one class inside another class

# Create classes
class Engine:
    
    def __init__( self, power ):
        self.power = power
    
class Vehicle:
    
    def __init__( self, wheels ):
        self.wheels = wheels
        self.engine = Engine( 400 )
        
    def get_power( self ):
        print( self.engine.power )

# Create object and print power        
object1 = Vehicle( 4 )
object1.get_power()
