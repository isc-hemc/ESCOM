from graph import graph
from cube import cube

def main ( ):
    parameters = [ ]
    n = int ( input ( "\n\tNumber to calculate firts n-Cubes: " ) )
    # cube ( n ): Return a list of tuples with the sum of the numbers to the
    # power '3' and the Computational Time of the Algorithm [ ( C ( n ), T ( n ) ) ].
    for i in range ( 1, n + 1 ):
        parameters.append ( cube ( i, 0 ) )
    print ( "\n\tCubesum ( ", n, " ): ", parameters [ len ( parameters ) - 1 ] [ 0 ], "\n" )
    graph ( parameters [ len ( parameters ) - 1 ], parameters, n )
main ( )
