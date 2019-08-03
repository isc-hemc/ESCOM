"""

ALGORITHM ANALYSIS:

Python File: main.py

Date: Tue October 10 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: Implementations of the addition and subtraction of two matrices.

"""

def add ( A, B ):
    n = len ( A )
    C = [ [ A [ i ] [ j ] + B [ i ] [ j ] for j in range ( n ) ] for i in range ( n ) ]
    # Return statement.
    return C

def subtrack ( A, B ):
    n = len ( A )
    C = [ [ A [ i ] [ j ] - B [ i ] [ j ] for j in range ( n ) ] for i in range ( n ) ]
    # Return statement.
    return C
