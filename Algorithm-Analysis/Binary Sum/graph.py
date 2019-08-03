import matplotlib.pyplot as plt
import numpy as np

def graph ( size, time ):
    # Window title.
    plt.figure ( "Temporal Complexity of Binary Sum Algorithm" )
    # Graph title.
    plt.title ( "Binary Sum:", color = ( 0.3, 0.4, 0.6 ), weight = "bold" )
    # Construct the parameters of the graph.
    t, n = parameters ( size, time )
    # Define the limits of the graph.
    plt.xlim ( 0, size )
    plt.ylim ( 0, time )
    # Proposed function: g ( n ) = ( 3/2 )n.
    _t = list ( map ( ( lambda x: x * 3/2 ), t ) )
    # Names of the axes.
    plt.xlabel ( "Size ( n )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    plt.ylabel ( "Time ( t )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    # Plot.
    plt.plot ( n, _t, "#800000", linestyle = "--", label = "g( n ) = ( 3/2 )n" )
    plt.plot ( n, t, "#778899", linewidth = 3, label = "E( n ) = n" )
    plt.legend ( loc = "lower right" )
    plt.show ( )

def parameters ( size, time ):
    # time vs size graph points.
    t, n = [ ], [ 0 ]
    # div: Auxiliar variable that help to plot the graph.
    div = float ( "{0:.2f}".format ( 1 / round ( time / size ) ) )
    # Time ( t ) parameters.
    for i in range ( time ):
        t.append ( i )
    # Size ( n ) parameters.
    for i in range ( time ):
        if ( i != 0 ):
            n.append ( float ( "{0:.2f}".format ( n [ i - 1 ] + div ) ) )
    # Return statement.
    return t, n
