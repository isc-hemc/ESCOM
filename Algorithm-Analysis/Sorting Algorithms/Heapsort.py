"""

ALGORITHM ANALYSIS:

Python File: Heapsort.py

Date: Tue November 14  20:03:00 2017

Credits: Hernandez Martinez Carlos David.

Email: davestring@outlook.com.

Description: Class that implements the Heap-Sort algorithm.

"""

import global_variables as gb

class Heapsort:
    # Class constructor.
    def __init__ ( self, dimensions ):
        assert len ( dimensions ) > 1
        self.dimensions = dimensions
        self.n = len ( dimensions )

    # Heapify subtree rooted at index i.
    def heapify ( self, i, j ):
        gb.time += 3
        right = 2 * j + 2
        left = 2 * j + 1
        largest = j
        # Verify if the left child exist and if it's greater than the root.
        gb.time += 1
        if ( left < i and self.dimensions [ j ] < self.dimensions [ left ] ):
            gb.time += 1
            largest = left
        # Verify if the right child exist and if it's greater than the root.
        gb.time += 1
        if ( right < i and self.dimensions [ largest ] < self.dimensions [ right ] ):
            gb.time += 1
            largest = right
        # Change the root if it's needed.
        gb.time += 1
        if ( largest != j ):
            gb.time += 4
            aux = self.dimensions [ j ]
            self.dimensions [ j ] = self.dimensions [ largest ]
            self.dimensions [ largest ] = aux
            # Heapify the root.
            self.heapify ( i, largest )

    # Heapsort algorithm.
    def heapsort ( self ):
        # Build the max heap.
        gb.time += 1
        for i in range ( self.n, -1, -1 ):
            gb.time += 1
            self.heapify ( self.n, i )
        # Extract the elements one by one.
        gb.time += 1
        for i in range ( ( self.n - 1 ), 0, -1 ):
            gb.time += 4
            aux = self.dimensions [ i ]
            self.dimensions [ i ] = self.dimensions [ 0 ]
            self.dimensions [ 0 ] = aux
            self.heapify ( i, 0 )
        return self.dimensions
