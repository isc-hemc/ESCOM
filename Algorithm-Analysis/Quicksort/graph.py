import matplotlib.pyplot as plt
import numpy as np
import gb


"""
                            Global variables:

proposed2: Proposed function for Quicktime algorithm. Depending if the user
           choose to sort a worst case this variable will take the value of
           "g ( n ) = 3/2 n^2". In other case "g ( n ) = n log ( n )".

proposed1: Proposed function for Partition algorithm. Depending if the user
           choose to sort a worst case this variable will take the value of
           "g ( n ) = 3/2 n". In other case "g ( n ) = n".

function2: This function for Quicksort will be displayed only if the user
           choose to sort a worst case and will take the value of:
           "T ( n ) = n^2".

function1: This function for Partition will be displayed only if the user
           choose to sort a worst case and will take the value of:
           "T ( n ) = n".

g2: This list will store the values of the proposed function for Quicksort.

g1: This list will store the values of the proposed function for Partition.
"""

proposed2 = ""
proposed1 = ""
function2 = ""
function1 = ""
g2 = [ ]
g1 = [ ]

"""
Function nlogn references to log ( n ^ n ) parameters or function points
to plot. This is the proposed function in the graph, where T( n ) is the
computational time of our algorithm and g( n ) the proposed function
such that T( n ) in ϴ ( g ( n ) ).
"""

def nlogn ( ):
    global g2, aux
    f = open ( "n log ( n ).txt", "r" )
    aux = f.readlines ( )
    g2 = list ( map ( lambda x: float ( x ) * 5/4, aux [ : len ( gb.n ) + 1 ] ) )
    f.close ( )

"""
Function labels it's controled implicitly by menu.py, depending the value of
gb.flag ( true or false ) will assign value to the string global variables and
they will help to distinguish the proposed and the computational algorithm time
in the graph.
"""

def labels ( ):
    global proposed2, proposed1, function2, function1, g1
    g1 = list ( map ( lambda x: 3/2 * x [ 1 ], gb._parameters ) )
    nlogn ( )
    if ( gb.flag ):
        # Worst case labels assignation.
        proposed2 = "g( n ) = ( 3/2 ) n^2"
        proposed1 = "g( n ) = ( 3/2 ) n"
        function2 = "T( n ) = n^2"
        function1 = "T( n ) = n"
    else:
        g1 = list ( np.arange ( 6, max ( g1 ) + 6, max ( g1 ) / len ( gb.n ) ) )
        # Any other case labels assignation.
        proposed2 = "g( n ) = n log ( n )"
        proposed1 = "g( n ) = n"
        function2 = None
        function1 = None

def graph ( ):
    labels ( )
    # Window title.
    plt.figure ( "Quicksort Algorithm", figsize = ( 14, 7 ) )

    # Right graph: Temporal complexity of Partition.
    plt.subplot ( 1, 2, 2 )
    # Figure title.
    plt.title ( "Partition ( " + str ( gb._parameters [ -1 ] [ 0 ] + 1 ) + ", " + str ( gb._parameters [ -1 ] [ 1 ] ) + " )" )
    # Parameter Time ( t ).
    _t = list ( map ( lambda x: x [ 1 ], gb._parameters ) )
    # Parameter Size ( n ).
    _s = list ( map ( lambda x: x [ 0 ] + 1, gb._parameters ) )
    # Axes names.
    plt.xlabel ( "Size ( n )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    plt.ylabel ( "Partition Time ( t )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    # Plot.
    plt.plot ( _s, _t, "#778899", linewidth = 3, label = function1 )
    plt.plot ( _s, g1, "#800000", linestyle = "--", label = proposed1 )
    plt.legend ( loc = "upper left" )

    # Left graph: Temporal complexity of Quicksort.
    plt.subplot ( 1, 2, 1 )
    # Figure title.
    plt.title ( "Quicksort ( " + str ( gb.parameters [ -1 ] [ 0 ] ) + ", " + str ( gb.parameters [ -1 ] [ 1 ] ) + " )" )
    # Parameter Time ( t ).
    t = list ( map ( lambda x: x [ 1 ], gb.parameters ) )
    # Parameter Size ( n ).
    s = list ( map ( lambda x: x [ 0 ], gb.parameters ) )
    # Axes names.
    plt.xlabel ( "Size ( n )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    plt.ylabel ( "Quicksort Time ( t )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    # Plot.
    plt.plot ( s, t, "#778899", linewidth = 3, label = function2 )
    plt.plot ( s, g2, "#800000", linestyle = "--", label = proposed2 )
    plt.legend ( loc = "upper left" )
    plt.show ( )
