# Program to print numbers until user enters 0

while True:
    
    # User enters numbers
    number = int( input('Enter a number: ') )
    
    # Exit if user enters 0
    if number == 0:
        print('Exiting...')
        break
    
    # Print number
    print('Entered:', number )