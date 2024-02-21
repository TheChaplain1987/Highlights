# Program that adds list items

# Create class
class Student:
    
    def __init__( self, scores ):
        self.scores = scores
        
    # Method to add numbers in a list
    def get_scores_sum( self ):
        total = 0
            
        for score in self.scores:
            total += score
                
        return total
            
# Define list of scores
scores = [ 55, 75, 80, 62, 77 ]

# Create object
s1 = Student( scores )

# Print results
print( s1.get_scores_sum() )
