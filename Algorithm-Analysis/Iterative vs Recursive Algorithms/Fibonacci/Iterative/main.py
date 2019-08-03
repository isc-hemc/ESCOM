from fibonacci import fibonacci
from graph import graph

def main ( ):
    n = -1
    while ( n <= 0 ):
        n = int ( input ( "\n\tFibonacci Number to Calculate: " ) )
    # fibonacci ( n ): Return the fibonacci number, the counter that takes to
    # find that number, and a list of the fibonacci numbers before 'fibo'.
    fibo, count, f = fibonacci ( n )
    print ( "\n\tFibonacci ( ", n, " ): ", fibo, "\n" )
    graph ( count, fibo, f, n )
main ( )
