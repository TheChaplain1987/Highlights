# Program to calculate simple interest

# User inputs data
principle = float( input('Enter principle: ') )
rate = float( input('Enter rate: ') )
time = float( input('Enter time: ') )

# Calculate simple interest and total
simple_interest = principle * rate * time * 0.01
total = principle + simple_interest

# Print results
print('Simple interst: ', simple_interest )
print('Total: ', total )
