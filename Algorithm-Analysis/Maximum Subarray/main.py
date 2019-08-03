"""

ALGORITHM ANALYSIS:

Python File: main.py

Date: Tue October 17 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: Implements the __main__ method and contains 2 functions:

    printer: Display on screen the results of the algorithms process.

    create: Creates the input array.

Commentaries: As an extra method, also from lines 77 to 91 writes in a
              file the latex code for the tables of the parameters points.

"""

from maximum_subarray import *
import global_variables as gb
import random as rnd
from plot import *

__FORMAT_1 = "\n\n\tBrute-Force Maximum Subarray Algorithm:"
__FORMAT_2 = "\n\n\tMaximum Crossing Subarray Algorithm:"
__FORMAT_3 = "\n\n\tMaximum Subarray Algorithm:"

def printer ( A, max_left, max_right, result, flag ):
    if ( flag == 1 ):
        print ( "\n\tArray to evaluate: {}".format ( A ) )
        print ( __FORMAT_1 )
    elif ( flag == 2 ):
        print ( __FORMAT_2 )
    else:
        print ( __FORMAT_3 )
    print ( "\n\tMaximum Subarray: {}".format ( A [ max_left : max_right + 1 ] ) )
    print ( "\n\tSum: {}\n\n".format ( result ) )

def create ( ):
    n = 2 ** 8
    A = [ rnd.randint ( -n, n ) for i in range ( n ) ]
    return A

if ( __name__ == "__main__" ):
    A = create ( )
    # Find the maximum subarray using a Brute-Force Algorithm.
    for i in range ( len ( A ) + 1 ):
        max_left, max_right, result = brute_force ( A [ :i ] )
        gb.parameters_1.append ( ( len ( A [ :i ] ), gb.time ) )
        gb.time = 0
    printer ( A, max_left, max_right, result, 1 )
    # Find the maximum subarray usign a Crossing Algorithm.
    for i in range ( len ( A ) + 1 ):
        high = int ( len ( A [ :i ] ) )
        mid = int ( high / 2 )
        max_left, max_right, result = crossing ( A [ :i ], 0, mid, high )
        gb.parameters_2.append ( ( len ( A [ :i ] ), gb.time ) )
        gb.time = 0
    printer ( A, max_left, max_right, result, 2 )
    # Find the maximum subarray usign a Recurrence Algorithm.
    for i in range ( 1, len ( A ) + 1 ):
        high = int ( len ( A [ :i ] ) )
        max_left, max_right, result = recurrence ( A [ :i ], 0, high )
        gb.parameters_3.append ( ( len ( A [ :i ] ), gb.time ) )
        gb.time = 0
    printer ( A, max_left, max_right, result, 3 )
    plot ( )

    # Writes the latex code for the tables of the parameters points for plotting.
    with open ( "parameters.txt", "w" ) as f:
        f.write ( str ( "\\begin{center} \n" ) )
        f.write ( str ( "\\begin{tabular}[.5cm]{ c c c c } \n" ) )
        f.write ( str ( "\\toprule \n" ) )
        f.write ( str ( "Size ( n ) & Brute-Force Time ( t ) & Crossing Time ( t ) & Recurrence Time ( t ) \\\\ \n" ) )
        f.write ( str ( "\midrule \n" ) )
        for i in range ( len ( gb.parameters_1 ) ):
            f.write ( "{} & {} & {} & {} \\\\ \n".format ( gb.parameters_1 [ i ] [ 0 ], gb.parameters_1 [ i ] [ 1 ], gb.parameters_2 [ i ] [ 1 ], gb.parameters_3 [ i ] [ 1 ] ) )
            if ( i != len ( gb.parameters_1 ) - 1 ):
                f.write ( str ( "\\cmidrule {1-4} \n" ) )
        f.write ( str ( "\\bottomrule \n" ) )
        f.write ( str ( "\\linebreak \n" ) )
        f.write ( str ( "\\end{tabular} \n" ) )
        f.write ( str ( "\\linebreak \\linebreak Table \n" ) )
        f.write ( str ( "\\end{center} \\hfill \n" ) )
