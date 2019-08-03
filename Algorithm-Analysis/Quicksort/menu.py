import numpy as np
import gb

def menu ( ):
    ans, length = -1, -1
    # Menu option 1: User must select if create a list of random numbers or
    # a list in the worst case for the algorithm, sorted in decreasing order.
    while ( ans != 1 and ans != 2 ):
        print ( "\n\n\t\t\tQUICK-SORT\n\n\t Select one of the following options." )
        print ( "\n\t1.- Random case." )
        print ( "\t2.- Worst case." )
        ans = int ( input ( "\tAnswer: " ) )
    # Menu option 2: User must choose the length of the list.
    while ( length < 0 ):
        print ( "\n\tLength of the list: " )
        length = int ( input ( "\tAnswer: " ) )
    # Create a list of random numbers. Otherwise a list in decreasing
    # order from 'length' to 0, on intervals of 1.
    if ( ans == 1 ):
        gb.n = list ( np.random.randint ( 0, 100, size = length ) )
    else:
        gb.n = list ( range ( length, 0, -1 ) )
        gb.flag = True
    print ( "\n\tList to sort: ", gb.n )
