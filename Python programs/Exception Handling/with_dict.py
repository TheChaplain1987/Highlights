# Program that uses exception handling with a dictionary

# create a try block
try:
    countries = {'Nepal' : 'Kathmandu', 'Sweden' : 'Stockholm', 'Italy' : 'Rome'}

    # take string input
    key = input('Enter a key to check: ')

    # print the value present at key
    print( countries[ key ] )
# create the except block
except:
    print('Key is not available')
