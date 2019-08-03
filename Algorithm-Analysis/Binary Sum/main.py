from binarysum import binarysum
from random import random
from graph import graph

# n and m are both of order Two to the power of n ( 2^(n) ) can be ( n > m ) or ( n = m ) but never ( n < m ).
# c: Stores the binary sum of 'a' and 'b'.
# a: Stores the first binary list.
# b: Stores the second binary list.
# n: Is the size of both lists.

def display ( a, b, c, counter ):
    DATAFORMAT = ""
    if ( len ( c ) > len ( a ) ): DATAFORMAT = "   "
    print ( "\n\tA: " + DATAFORMAT, a )
    print ( "\tB: " + DATAFORMAT, b )
    print ( "\tC: ", c )
    print ( "\n\tOrder of the sum: ", int ( pow ( 2, len ( c ) - 1 ) ), "\n" )
    print ( "\tSize Sum List: ", len ( c ), "\t\tTime: ", counter, "\n" )

def generate ( ):
    a, b, n, m = [ ], [ ], 0, 1
    # Define the size of a-b lists ( n-m respectively ).
    while ( n < m ):
        rnd = ( int ( random ( ) * 5 ) + 1 )
        n = int ( pow ( 2, rnd ) )
        rnd = ( int ( random ( ) * 5 ) + 1 )
        m = int ( pow ( 2, rnd ) )
    # Generate both binary numbers as integer lists.
    for i in range ( n ):
        a.insert ( 0, ( ( int ( random ( ) * 2 ) + 0 ) ) )
        if ( i >= m ):
            b.insert ( 0, 0 )
        else:
            b.insert ( 0, ( ( int ( random ( ) * 2 ) + 0 ) ) )
    # Return statement.
    return a, b

def main ( ):
    a, b = generate ( )
    c, count = binarysum ( a, b )
    display ( a, b, c, count )
    graph ( len ( c ), count )
main ( )
