# Program to print a persons first and last name

# Function to combine names
# INPUT  name1 = first name
#        name2 = last name
# OUTPUT print both names combined
def full_name( name1, name2 ):

    cat = name1 + ' ' + name2

    return cat

# User enters names   
firstName = input('Enter first name: ')
lastName  = input('Enter last name: ')

# Print full name
print('Full name:', full_name( firstName, lastName ) )
