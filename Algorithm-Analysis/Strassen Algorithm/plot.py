"""

ALGORITHM ANALYSIS:

Python File: main.py

Date: Tue October 10 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: This module plots the temporal complexity of the algorithms Strassen
             and IJK if it's required. Also has 2 global variables that have the
             following function:

    _function: If the size of the matrices it's bigger or equal than 2^k where k = 10
               then, this variables takes the value of "g ( n ) = n^3", in other case,
               takes the value of "g ( n ) = 3/2 ( n^2.81 )" that is an asymptotic
               proposed function.

    function: Stores the function for Strassen's algorithm, this value it's constant
              because the complexity of this algorithm it's the same in the worst or
              best case: "f ( n ) = n^2.81".

"""

import matplotlib.pyplot as plt
import global_variables as gb
import numpy as np
import math

function = "Strassen algorithm function: f ( n ) = n^2.81"
_function = ""

def plot ( ):
    global function, _function
    # Window title.
    plt.figure ( "Strassen's Algorithm", figsize = ( 14, 7 ) )
    # Graph title.
    plt.title ( "Strassen ( " + str ( gb.parameters [ -1 ] [ 0 ] ) + ", " + str ( gb.parameters [ -1 ] [ 1 ] ) + " ):", color = ( 0.3, 0.4, 0.6 ), weight = "bold" )
    # Parameters S ( n ) -size- of the graph.
    s = list ( map ( lambda x: x [ 0 ], gb.parameters ) )
    # Parameters T ( t ) -time- of the graph for Strassen.
    t = list ( map ( lambda x: x [ 1 ], gb.parameters ) )
    if ( gb.flag == True ):
        # Compares the complexities of Strassen against ijk algorithms.
        # Parameters T ( t ) -time- of the graph for ijk.
        _t = list ( map ( lambda x: x [ 1 ], gb._parameters ) )
        _function = "ijk-Algorithm function: g ( n ) = n^3"
    else:
        # In other case, we propose an asymptotic function g ( n ) = 3/2 n^2.81
        # Parameters T ( t ) -time- of the graph.
        _t = list ( map ( lambda x: ( 3/2 ) * x [ 1 ], gb.parameters ) )
        _function = "Proposed asymptotic function: g ( n ) = 3/2 ( n^2.81 )"
    # Axes names.
    plt.xlabel ( "Size ( n )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    plt.ylabel ( "Time ( t )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    # Plot.
    plt.plot ( s, t, "#778899", linewidth = 3, label = function )
    plt.plot ( s, _t, "#800000", linestyle = "--", label = _function )
    plt.legend ( loc = "upper left" )
    plt.show ( )
