from euclidean import algorithm
from random import random
from graph import graph
from fibonacci import *

# r: Store the remainder of the division of ( n/m ).
# gcd: Store the Greatest Common Divisor.
# 'n' and 'm' are two random numbers.

def menu ( ):
    ans = 0
    print ( "\n\n\t\tEUCLIDEAN ALGORITHM:" )
    while ( ans != 1 and ans != 2 ):
        print ( "\n\t1.- Calculate GCD using random numbers." )
        print ( "\t2.- Calculate GCD of Fibonacci numbers." )
        ans = int ( input ( "\tAnswer [1/2]: " ) )
    # Return statement.
    return ans

def display ( n, m, gcd ):
    print ( "\n\tGreatest Common Divisor: gcd ( ", n, ", ", m, " ) = ", gcd, "\n" )

def generate ( ):
    n, m = 0, 1
    while ( n < m ):
        n = ( int ( random ( ) * 1000 ) + 1 )
        m = ( int ( random ( ) * 1000 ) + 1 )
    # Return statement.
    return n, m

def main ( ):
    ans = menu ( )
    if ( ans == 2 ):
        print ( "\n\tFirst 'n' Fibonacci's to calculate: " )
        limit = int ( input ( "\tAnswer: " ) )
        # Return a Fibonacci numbers list.
        fibo = fibolist ( limit )
        # Assign the last two Fibonacci's in the list.
        n, m = fibo [ len ( fibo ) - 1 ], fibo [ len ( fibo ) - 2 ]
    else:
        # Generate random numbers.
        n, m = generate ( )
    # Return: GCD, algorithm counter for temporal complexity and gcd process list.
    result, count, gcd = algorithm ( n, m )
    # Display on screen the result.
    display ( n, m, result )
    # Graph of the Temporal Complexity of the Euclidean Algorithm.
    graph ( n, m, count, gcd )

main ( )
