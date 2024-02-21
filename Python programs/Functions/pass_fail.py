# Program to check is student passes or fails using functions

# Function for checking pass/fail ( 40+ passes )
# INPUTS  = number: the grade of the student
# OUTPUTS = True is pass, False is fail 
def passFail( number ):
    if number >= 40:
        result = True
    else:
        result = False
        
    return result

# Check grade  
grade = passFail( int( input('Enter grade: ') ) )

# Print pass/fail
if grade:
    print('You pass!')
else:
    print('You fail! :(')
