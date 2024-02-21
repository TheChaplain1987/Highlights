# Program to detect the occurrence of a character

# User enters a string
string = input('Enter a string: ')

# User enters a character to check
char = input('Enter character to check for: ')

# Variable to count occurrences
occurrence = 0

# If the character is present, occurrence + 1
for index in string:
    if index == char:
        occurrence += 1

# Print occurrences
print('Occurrences: ', occurrence)
