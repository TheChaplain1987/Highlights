# Program to count the number of digits

# User enters number
number = int( input('Enter an integer: ') )

# Define an indexing variable
count = 0

# Divide number by 10 to cut off the last digit
# Advance count by 1 and continue until number is 0
while number != 0:
    number = int(number / 10)
    count += 1

# Print the number of digits ( number of interations )
print('Number of digits: ', count )