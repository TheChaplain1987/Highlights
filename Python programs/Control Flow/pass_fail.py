# Program to check if a student passed or failed

grade = int( input('Enter grade: ') )

if grade < 0 or grade > 100:
    print("Invalid grade!")
elif grade > 40:
    print('Pass')
else:
    print('Fail')