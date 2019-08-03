import matplotlib.pyplot as plt
import numpy as np

def graph ( count, fibo, f, n ):
    # Window title.
    plt.figure ( "Fibonacci Iterative Algorithm" )
    # Graph title.
    plt.title ( "Fibonacci ( " + str ( n ) + " ): " + str ( fibo ) )
    # Parameter time ( t ) of the graph.
    t = np.arange ( 0, count, ( count / ( len ( f ) + 1 ) ) )
    _t = list ( map ( ( lambda x: x * ( 3 / 2 ) ), t ) )
    _f = np.arange ( 0, len ( f ) + 1 )
    # Names of the axes.
    plt.xlabel ( "Time ( t )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    plt.ylabel ( "Fibonacci ( f )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    # Plot.
    plt.plot ( _f, t, "#778899", linewidth = 3, label = "T( n ) = ( n )" )
    plt.plot ( _f, _t, "#800000", linestyle = "--", label = "g( n ) = ( 3/2 )( n )" )
    plt.legend ( loc = "lower right" )
    plt.show ( )
