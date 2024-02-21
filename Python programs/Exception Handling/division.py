# Program that uses division with exception handling

# create a try block
try:
    # take input for numerator
    numerator = int(input('Enter numerator: '))
    # take input for denominator
    denominator = int(input('Enter denominator: '))

    # Divide numerator by denominator and print the result
    print( f'Result: { float( numerator / denominator ) }')

# create the except block
except ZeroDivisionError:
    print('Denominator cannot be 0. Try again.')
