"""

ALGORITHM ANALYSIS:

Python File: main.py

Date: Tue November 14  20:03:00 2017

Credits: Hernandez Martinez Carlos David.

Email: davestring@outlook.com.

Description: Implements the __main__ method and contains 2 functions:

    printer_1: Display on screen the list to sort.

    printer_2: Display on screen the sorted list.

    menu: Allows the user to create an algorithm.

"""

import global_variables as gb
from Heapsort import *
from Cocktail import *
from Shell import *
from plot import *
import random as rnd

def menu ( ):
    print ( "\n\n\tSorting Algorithms: Select one of the following options." )
    print ( "\n\t1.- Heap-Sort." )
    print ( "\t2.- Cocktail-Sort." )
    print ( "\t3.- Shell-Sort.")
    return int ( input ( "\tAnswer: " ) )

def printer_1 ( dimensions, j ):
    if ( j == 0 ):
        case = "Best case:"
    if ( j == 1 ):
        case = "Random case:"
    if ( j == 2 ):
        case = "Worst case:"
    print ( "\n\t{}\n\n\tList to sort: {}".format ( case, dimensions ) )

def printer_2 ( dimensions ):
    print ( "\n\tSorted List:  {}\n".format ( dimensions ) )

if ( __name__ == "__main__" ):
    ans, j = menu ( ), 0
    while ( j < 3 ):
        # Best, random ans worst case of each algorithm.
        if ( j == 0 ):
            dimensions = [ i for i in range ( 0, 1000 ) ]
        if ( j == 1 ):
            dimensions = [ rnd.randint ( 0, 1000 ) for i in range ( 1000 ) ]
        if ( j == 2 ):
            dimensions = [ i for i in range ( 1000, 0, -1 ) ]
        printer_1 ( dimensions, j )
        # Sort the list dimensions.
        for i in range ( 2, len ( dimensions ) + 1 ):
            if ( ans == 1 ):
                algorithm = Heapsort ( dimensions [ :i ] )
                sort = algorithm.heapsort ( )
            if ( ans == 2 ):
                algorithm = Cocktail ( dimensions [ :i ], 0, len ( dimensions [ :i ] ) - 1 )
                sort = algorithm.cocktail ( )
            if ( ans == 3 ):
                algorithm = Shell ( dimensions [ :i ] )
                sort = algorithm.shellsort ( )
            if ( j == 0 ):
                gb.parameters_1.append ( ( len ( dimensions [ :i ] ), gb.time ) )
            if ( j == 1 ):
                gb.parameters_2.append ( ( len ( dimensions [ :i ] ), gb.time ) )
            if ( j == 2 ):
                gb.parameters_3.append ( ( len ( dimensions [ :i ] ), gb.time ) )
            gb.time = 0
        j = j + 1
        printer_2 ( sort )
    plot ( ans )
