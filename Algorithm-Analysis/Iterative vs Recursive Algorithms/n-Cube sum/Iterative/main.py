from graph import graph
from cube import cube

def main ( ):
    n = int ( input ( "\n\tNumber to calculate firts n-Cubes: " ) )
    # cube ( n ): Return the _sum of the first 'n' cubes, the computational time
    # of the algorithm and a list of the sum of nth cubes.
    _sum, count, cubelist = cube ( n )
    print ( "\n\tThe sum of the first ", n, " cubes is: C ( ", n, " ) = ", _sum, "\n" )
    graph ( _sum, count, cubelist, n )
main ( )
