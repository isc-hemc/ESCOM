from fibonacci import fibonacci
from graph import graph

def main ( ):
    n, parameters = -1, [ ]
    while ( n <= 0 ):
        n = int ( input ( "\n\tFibonacci Number to Calculate: " ) )
    # fibonacci ( n ): Return a list of tuples with the Fibonacci numbers
    # and the Computational Time of the Algorithm [ ( F ( n ), T ( n ) ) ].
    for i in range ( 1, n + 1 ):
        parameters.append ( fibonacci ( i, 0 ) )
    print ( "\n\tFibonacci ( ", n, " ): ", parameters [ len ( parameters ) - 1 ] [ 0 ], "\n" )
    graph ( parameters [ len ( parameters ) - 1 ], parameters, n )
main ( )
