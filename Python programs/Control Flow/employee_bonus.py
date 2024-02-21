# Program to calculate bonus based on years of service

# take float input for salary
salary = float( input('Please enter salary: ') )

# take integer input for years
years = int( input('Please enter years of service: ') )

# check if years worked is greater than 5 or not
if( years > 5 ): 
    # calculate 5% bonus using 5 * salary / 100
    bonus = 5 * salary / 100
    # print bonus
    print('Bonus: ', bonus )
else:
    print('No bonus...')
