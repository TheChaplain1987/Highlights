# Program to split the bill with friends

# Get user input
total_people = int( input('Enter number of people: ') )
total_bill = float( input('Enter bill amount: ') )
tip = float( input('Enter tip percentage: '))

# Calculate tip based on total bill
total_tip = total_bill * ( ( tip / 100 ) )

# Calculate split bill and tip
split_bill = format( total_bill / total_people, ".2f" )
split_tip = format( total_tip / total_people, ".2f" )

print('Split bill: ', split_bill, 'per person with a', split_tip, 'tip')
