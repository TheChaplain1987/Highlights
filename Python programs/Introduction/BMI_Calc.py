# Program to calcuate body mass index

# User inputs data
weight = float( input('Please enter weight: ') )
height = float( input('Please enter height: ') )

# Calculate BMI with pounds and inches
BMI = format( ( weight / ( height ** 2 ) ) * 703, ".2f" )

# Print BMI
print('BMI: ', BMI )
