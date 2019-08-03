"""

ALGORITHM ANALYSIS:

Python File: main.py

Date: Tue October 10 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: Implements the __main__ method and contains a function named printer
             that displays in console the matrices A, B and the product of A*B.

"""

import global_variables as gb
from create_matrices import *
from ijk_product import *
from strassen import *
from plot import *

def printer ( A, B, C ):
    # Validates the condition of matrices of [ 2^n x 2^n ] size.
    assert len ( A ) == len ( B ) == len ( C )

    print ( "\n\tStrassen Algorithm:" )
    print ( "\n\tMatrix A:\n" )
    list ( map ( lambda x: print ( "\t{}".format ( x ) ), A ) )
    print ( "\n\tMatrix B:\n" )
    list ( map ( lambda x: print ( "\t{}".format ( x ) ), B ) )
    print ( "\n\tProduct A * B:\n" )
    list ( map ( lambda x: print ( "\t{}".format ( x ) ), C ) )
    n = len ( C )
    print ( "\n\tWhere: A, B, C ∈ M [ {}x{} ] ( ℤ+ )".format ( n, n ) )
    print ( "\n\tStrassen's algorithm parameters: {}\n".format ( gb.parameters ) )
    if ( gb.flag == True ):
        print ( "\tIJK algorithm parameters: {}\n".format ( gb._parameters ) )


if ( __name__ == "__main__" ):
    power = int ( input ( "\n\tAdd an nth-power: " ) )
    if ( power >= 8 ):
        gb.flag = True
    for i in range ( 1, power + 1 ):
        # Strassen algorithm.
        n = int ( math.pow ( 2, i ) )
        A, B = create ( n )
        C = strassen ( A, B )
        gb.parameters.append ( ( n, gb.time ) )
        gb.time = 0
        # For big matrices compare the Strassen's algorithm with the ijk algorithm.
        if ( gb.flag == True ):
            _C = ijk_product ( A, B )
            gb._parameters.append ( ( n, gb._time ) )
            gb._time = 0
    printer ( A, B, C )
    plot ( )
