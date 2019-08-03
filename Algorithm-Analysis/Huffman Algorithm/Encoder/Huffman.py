"""

ALGORITHM ANALYSIS:

Python File: Huffman.py

Date: Tue November 21 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: Implements Huffman's algorithm.

"""

from collections import Counter
import heapq

class Huffman:
    # Class constructor.
    def __init__ ( self, txtin ):
        self.probability = { }
        self.frequency = { }
        self.txtin = txtin
        self.codes = { }
        self.txtout = ""
        self.result = ""
        self.tree = [ ]

    # Set the frequency of appereance of each symbol.
    def setFrequency ( self ):
        total = len ( self.txtin ) + 1
        c = Counter ( self.txtin )
        self.probability = {}
        self.frequency = {}
        for char, counter in c.items ( ):
            self.probability [ char ] = float ( counter ) / total
            self.frequency [ char ] = counter
        self.probability [ "end" ] = 1.0 / total
        self.frequency [ "end" ] = 1

    # Create the Huffman's algorithm tree.
    def setTree ( self ):
        # Add the symbols to the priority stack based on heaps.
        for char, freq in self.frequency.items ( ):
            # The stack its ordered by priority and depth.
            heapq.heappush ( self.tree, ( freq, 0, char ) )
        # Start to 'mix' contiguous symbols until the row has an element.
        while ( len ( self.tree ) > 1 ):
            # First and second less frequents symbols.
            e1 = heapq.heappop ( self.tree )
            e2 = heapq.heappop ( self.tree )
            node = ( e1 [ 0 ] + e2 [ 0 ], max ( e1 [ 1 ], e2 [ 1 ] ) + 1, [ e1, e2 ] )
            heapq.heappush ( self.tree, node )
        # Return the tree without the row.
        self.tree = self.tree [ 0 ]

    def setCodes ( self ):
        # Depth-First Search stack.
        searchStack = [ ]
        searchStack.append ( self.tree + ( "", ) )
        while ( len ( searchStack ) > 0 ):
            element = searchStack.pop ( )
            if ( type ( element [ 2 ] ) == list ):
                # The node it's not a leaf.
                searchStack.append ( element [ 2 ] [ 1 ] + ( element [ -1 ] + "1", ) )
                searchStack.append ( element [ 2 ] [ 0 ] + ( element [ -1 ] + "0", ) )
            else:
                # The node it's a leaf.
                code = element [ -1 ]
                self.codes [ element [ 2 ] ] = code
            pass

    def encode ( self ):
        for char in self.txtin:
            code = self.codes [ char ]
            self.result = self.result + code
        # Add a 1 to the left and the END marker.
        self.result = "1" + self.result + self.codes [ "end" ]
        self.result = int ( self.result, 2 )
