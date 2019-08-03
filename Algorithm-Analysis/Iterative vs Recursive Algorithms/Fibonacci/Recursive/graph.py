import matplotlib.pyplot as plt
import numpy as np

def graph ( fibo, parameters, n ):
    t, f = [ ], [ ]
    # Window title.
    plt.figure ( "Fibonacci Recursive Algorithm" )
    # Graph title.
    plt.title ( "Fibonacci ( " + str ( n ) + " ): " + str ( fibo [ 0 ] ) )
    # Parameter Time ( t ) and Fibonacci ( n ) of the graph.
    f = np.arange ( 0, len ( parameters ) )
    t = list ( map ( ( lambda x: x [ 1 ] ), parameters ) )
    # Proposed function g ( n ) = ( 3/2 ) ( n ).
    _t = list ( map ( ( lambda x: x * ( 3 / 2 ) ), t ) )
    # Names of the axes.
    plt.ylabel ( "Time ( t )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    plt.xlabel ( "Fibonacci ( f )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    # Plot.
    plt.plot ( f, t, "#778899", linewidth = 3, label = "T( n ) = ( Φ^n )" )
    plt.plot ( f, _t, "#800000", linestyle = "--", label = "g( n ) = ( 3/2 )( Φ^n )" )
    plt.legend ( loc = "upper left" )
    plt.show ( )
