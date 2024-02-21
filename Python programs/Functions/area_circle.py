# Program to calcute the radius of a circle

def compute_area( rad ):
    area = 3.14 * rad * rad
    return area
    
radius = float( input('Enter the radius: ') )

print('Area: ', compute_area( radius ) )
   