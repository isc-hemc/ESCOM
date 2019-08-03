"""

ALGORITHM ANALYSIS:

Python File: plot.py
Date: Tue November 28 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: This module plots the in polinomial time the algorithm verify_hamiltonian.

"""

import matplotlib.pyplot as plt
import numpy as np
import gb

def plot ( ):
    # Window title.
    plt.figure ( "Hamiltonian-Cycle:" )
    # Parameter Time ( t ) and Cube ( n ) of the graph.
    s = list ( map ( lambda x: x [ 0 ], gb.parameters ) )
    t = list ( map ( lambda x: x [ 1 ], gb.parameters ) )
    # Proposed function: g( n ) = ( 3/2 )n.
    _t = [ 1/3 * i ** 2 for i in range ( t [ 0 ], len ( gb.parameters ) + t [ 0 ] ) ]
    # Names of the axes.
    plt.ylabel ( "Time ( t )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    plt.xlabel ( "Graph Size ( n )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    # Plot.
    plt.plot ( s, _t, "#800000", linestyle = "--", label = "g( n ) = ( 3/2 )( n^2 )" )
    plt.plot ( s, t, "#778899", linewidth = 3, label = "T( n ) = ( n^2 )" )
    plt.legend ( loc = "lower right" )
    plt.show ( )
