"""

ALGORITHM ANALYSIS:

Python File: main.py

Date: Tue October 10 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: Implements two methods:

    split_in_sub_matrices: Split the input matrices in sub-matrices of size n/2 x n/2.

    join_sub_matrices: Join 4 sub-matrices of size n/2 x n/2 in a resulting matrix.

"""

def split_in_sub_matrices ( A, B, n ):
    # Initialize the sub-matrices.
    A11, A12, A21, A22 = [ ], [ ], [ ], [ ]
    B11, B12, B21, B22 = [ ], [ ], [ ], [ ]
    # Fill the sub-matrices.
    for i in range ( n ):
        A11.append ( A [ i ] [ :n ] )
        A12.append ( A [ i ] [ n: ] )
        A21.append ( A [ n + i ] [ :n ] )
        A22.append ( A [ n + i ] [ n: ] )
        B11.append ( B [ i ] [ :n ] )
        B12.append ( B [ i ] [ n: ] )
        B21.append ( B [ n + i ] [ :n ] )
        B22.append ( B [ n + i ] [ n: ] )
    # Return statement.
    return A11, A12, A21, A22, B11, B12, B21, B22

def join_sub_matrices ( C11, C12, C21, C22, n ):
    C, sub_size = [ ], int ( n / 2 )
    for i in range ( sub_size ):
        C.append ( C11 [ i ] + C12 [ i ] )
    for i in range ( sub_size ):
        C.append ( C21 [ i ] + C22 [ i ] )
    # Return statement.
    return C
