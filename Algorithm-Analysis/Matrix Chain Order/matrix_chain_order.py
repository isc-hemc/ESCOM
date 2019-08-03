"""

ALGORITHM ANALYSIS:

Python File: matrix_chain_order.py

Date: Wed November 01 20:03:00 2017

Credits: Hernandez Martinez Carlos David.

Email: davestring@outlook.com.

Description: Implements the __main__ method and contains a function named printer
             that displays in console the matrices 'm' and 's'. Also contains the
             method matrix_chain_order which find the minimum scalar product and
             print_optimal_parens finds the parenthesization for this optimal scalar
             product found.

"""

import random as rnd

parenthesization = ""

def matrix_chain_order ( p ):
    n = len ( p )
    # Initialize the matrices of size n x n.
    m = [ [ "x" for i in range ( 1, n + 1 ) ] for j in range ( 1, n + 1 ) ]
    s = [ [ "x" for i in range ( 1, n + 1 ) ] for j in range ( 1, n + 1 ) ]
    # m [ i, i ] = 0 for i = 1, ..., n (minimum costs for chains of length 1).
    for i in range ( n ):
        m [ i ] [ i ] = 0
    # Finds the optimal matrix-chain product.
    for l in range ( 2, n ):
          for i in range ( 1, n - l + 1 ):
              j = i + l - 1
              m [ i ] [ j ] = int ( 1e100 )
              for k in range ( i, j ):
                  q = m [ i ] [ k ] + m [ k + 1 ] [ j ] + ( p [ i - 1 ] * p [ k ] * p [ j ] )
                  if ( q < m [ i ] [ j ] ):
                      m [ i ] [ j ] = q
                      s [ i ] [ j ] = k

    return m, s

def print_optimal_parens ( s, i, j ):
    global parenthesization
    if ( i == j ):
        parenthesization = parenthesization + "A{}".format ( i )
    else:
        parenthesization = parenthesization + "("
        print_optimal_parens ( s, i, s [ i ] [ j ] )
        print_optimal_parens ( s, s [ i ] [ j ] + 1, j )
        parenthesization = parenthesization + ")"

def printer ( m, s, p ):
    print ( "\n\n\tMatrix Chain Order:\n" )
    print ( "\n\tMatrix chain: {}\n".format ( p ) )
    print ( "\n\tTable m:\n" )
    for i in range ( len ( m ) ):
        print ( "\t{}".format ( m [ i ] ) )
    print ( "\n\tTable s:\n" )
    for i in range ( len ( s ) ):
        print ( "\t{}".format ( s [ i ] ) )
    print ( "\n\tParenthesization: {}\n".format ( parenthesization ) )

if ( __name__ == "__main__" ):
    #p = [ rnd.randint ( 2, 50 ) for i in range ( 2 ** rnd.randint ( 1, 4 ) ) ]
    #p = [ 30, 35, 15, 5, 10, 20, 25 ]
    #p = [ 4, 10, 3, 12, 20, 7 ]
    #p = [ 3, 5, 2, 2 ]
    p = [ 10, 8, 12, 2, 5 ]
    m, s = matrix_chain_order ( p )
    print_optimal_parens ( s, 1, len ( p ) - 1 )
    printer ( m, s, p )
