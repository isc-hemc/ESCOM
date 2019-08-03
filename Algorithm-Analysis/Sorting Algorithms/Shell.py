"""

ALGORITHM ANALYSIS:

Python File: Shell.py

Date: Tue November 14  20:03:00 2017

Credits: Hernandez Martinez Carlos David.

Email: davestring@outlook.com.

Description: Class that implements the Shell-Sort algorithm.

"""

import global_variables as gb

class Shell:
    # Class constructor.
    def __init__ ( self, dimensions ):
        assert len ( dimensions ) > 1
        self.dimensions = dimensions
        self.n = len ( dimensions )
        self.gap = int ( self.n / 2 )

    # Shellsort algorithm.
    def shellsort ( self ):
        # Do a gapped insertion sort for the gap size.
        # The first gap elements of dimensions [ 0 .. gap - 1 ] are already in
        # gapped order then, keep adding one more element until the entire array
        # is gap sorted.
        gb.time += 1
        while ( self.gap > 0 ):
            # Add dimensions [ i ] to the elements that have been gap sorted.
            gb.time += 1
            for i in range ( self.gap, self.n ):
                # Save dimensions [ i ] in the variable 'temp', and make a hole
                # at i position.
                gb.time += 1
                temp = self.dimensions [ i ]
                # Shift earlier gap-sorted elements up until the correct location
                # for dimensions [ i ] is found.
                gb.time += 1
                j = i
                gb.time += 1
                while ( j >= self.gap and self.dimensions [ j - self.gap ] > temp ):
                    gb.time += 1
                    self.dimensions [ j ] = self.dimensions [ j - self.gap ]
                    gb.time += 1
                    j = j - self.gap
                # Put 'temp' ( the original dimensions [ i ] ) in its correct location.
                gb.time += 1
                self.dimensions [ j ] = temp
            gb.time += 1
            self.gap = int ( self.gap / 2 )
        return self.dimensions
