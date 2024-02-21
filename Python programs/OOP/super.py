# Program that uses super()

# create the Animal class
class Animal:
    
    def eat( self ):
        print('I can eat food')

# create the Dog class
class Dog( Animal ):
    
    def bark( self ):
        print('I can bark')
        super().eat()

# create an object of the Dog class
bob_barker = Dog()

# call the eat() method using the object
bob_barker.eat()
