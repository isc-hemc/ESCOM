import matplotlib.pyplot as plt
import numpy as np

def graph ( n, m, count, gcd ):
    # Window title.
    plt.figure ( "Temporal Complexity of Euclidean Algorithm" )
    # Graph title.
    plt.title ( "Euclidean ( " + str ( n ) + ", " + str ( m ) + " ):", color = ( 0.3, 0.4, 0.6 ), weight = "bold" )
    # Parameter Time ( t ) of the graph.
    t = np.arange ( 0, count, ( count / len ( gcd ) ) )
    # Parameter Euclidean ( n ) of the list
    gcd.reverse ( )
    # Names of the axes.
    plt.xlabel ( "Euclidean ( e )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    plt.ylabel ( "Time ( t )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    # Proposed function: g ( n ) = ( 3/2 ) log ( n ).
    _t = list ( map ( ( lambda x: x * ( 3 / 2 ) ), t ) )
    # Plot.
    plt.plot ( gcd, _t, "#800000", linestyle = "--", label = "g( n ) = ( 3/2 ) log ( n )" )
    plt.plot ( gcd, t, "#778899", linewidth = 3, label = "E( n ) = log ( n )" )
    plt.legend ( loc = "lower right" )
    plt.show ( )
