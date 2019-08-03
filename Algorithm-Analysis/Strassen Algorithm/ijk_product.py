"""

ALGORITHM ANALYSIS:

Python File: main.py

Date: Tue October 10 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: Implementation of the ijk-algorithm with the purpose of calculting the 
             product of the matrices A and B.

"""

import global_variables as gb

def ijk_product ( A, B ):
    # Validates the condition of matrices of [ 2^n x 2^n ] size.
    assert len ( A ) == len ( A [ 0 ] ) == len ( B ) == len ( B [ 0 ] )
    assert type ( A ) == list and type ( B ) == list

    gb._time += 1
    n = len ( A )
    gb._time += 1
    C = [ [ 0 for i in range ( n ) ] for j in range ( n ) ]
    gb._time += 1
    for i in range ( n ):
        gb._time += 1
        for j in range ( n ):
            gb._time += 1
            for k in range ( n ):
                gb._time += 1
                C [ i ] [ j ] += A [ i ] [ k ] * B [ k ] [ j ]
                gb._time += 1
            gb._time += 1
        gb._time += 1
    gb._time += 1
    # Return statement.
    gb._time += 1
    return C
