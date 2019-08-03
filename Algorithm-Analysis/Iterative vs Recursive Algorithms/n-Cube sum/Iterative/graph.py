import matplotlib.pyplot as plt
import numpy as np

def graph ( _sum, count, cubelist, n ):
    # Window title.
    plt.figure ( "First 'n' Cubes: Iterative Algorithm" )
    # Graph title.
    plt.title ( "CubeSum ( " + str ( n ) + " ): " + str ( _sum ) )
    # Parameter Time ( t ) of the graph.
    t = np.arange ( 0, count, ( count / ( len ( cubelist ) ) ) )
    # Parameter CubeSum ( n ) of the graph.
    c = np.arange ( 0, len ( cubelist ) )
    # Proposed function: g( n ) = ( 3/2 )n.
    _t = list ( map ( ( lambda x: x * ( 3 / 2 ) ), t ) )
    # Names of the axes.
    plt.ylabel ( "Time ( t )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    plt.xlabel ( "CubeSum ( n )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    # Plot.
    plt.plot ( c, _t, "#800000", linestyle = "--", label = "g( n ) = ( 3/2 )( n )" )
    plt.plot ( c, t, "#778899", linewidth = 3, label = "T( n ) = ( n )" )
    plt.legend ( loc = "lower right" )
    plt.show ( )
