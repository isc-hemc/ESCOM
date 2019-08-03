"""

ALGORITHM ANALYSIS:

Python File: Cocktail.py

Date: Tue November 14  20:03:00 2017

Credits: Hernandez Martinez Carlos David.

Email: davestring@outlook.com.

Description: Class that implements the Cocktail-Sort algorithm.

"""

import global_variables as gb

class Cocktail:
    # Class constructor.
    def __init__ ( self, dimensions, start, end ):
        assert len ( dimensions ) > 1
        self.dimensions = dimensions
        self.n = len ( dimensions )
        self.swapped = True
        self.start = start
        self.end = end

    def cocktail ( self ):
        gb.time += 1
        while ( self.swapped ):
            # Reset the swapped flag because it might be true in the next iteration.
            gb.time += 1
            self.swapped = False

            # Loop from left to right.
            gb.time += 1
            for i in range ( self.start, self.end ):
                gb.time += 1
                if ( self.dimensions [ i ] > self.dimensions [ i + 1 ] ):
                    gb.time += 4
                    aux = self.dimensions [ i ]
                    self.dimensions [ i ] = self.dimensions [ i + 1 ]
                    self.dimensions [ i + 1 ] = aux
                    self.swapped = True

            # If nothing were moved then the array it's sorted.
            gb.time += 1
            if ( self.swapped == False ):
                break
            # Otherwise, reset the flag so can be used in the next stage.
            gb.time += 1
            self.swapped = False
            # Move the end back in one unit, because the previous loop
            # moved the greater number to its rightfull spot.
            gb.time += 1
            self.end = self.end - 1

            # Loop from right to left.
            gb.time += 1
            for i in range ( self.end - 1, self.start - 1, -1 ):
                gb.time += 1
                if ( self.dimensions [ i ] > self.dimensions [ i + 1 ] ):
                    gb.time += 4
                    aux = self.dimensions [ i ]
                    self.dimensions [ i ] = self.dimensions [ i + 1 ]
                    self.dimensions [ i + 1 ] = aux
                    self.swapped = True

            # Increase the starting point, because the previous loop
            # moved the next smallest number to its rightfull spot.
            gb.time += 1
            self.start = self.start + 1
        return self.dimensions
