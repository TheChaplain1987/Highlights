# Program using variable arguments

# create the function
def multiply_numbers( *args ):
    product = 1
    
    for index in args:
        product *= index
        
    return product

# get three integer inputs
n1 = int( input('Enter integer 1: ') )
n2 = int( input('Enter integer 2: ') )
n3 = int( input('Enter integer 3: ') )

# call the function
result = multiply_numbers( n1, n2, n3 )

# print the result
print( f"Result: { result }" )
