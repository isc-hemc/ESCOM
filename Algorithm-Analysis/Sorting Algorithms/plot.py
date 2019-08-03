"""

ALGORITHM ANALYSIS:

Python File: plot.py

Date: Tue November 14  20:03:00 2017

Credits: Hernandez Martinez Carlos David.

Email: davestring@outlook.com.

Description: Plot the complexity of the selected algorithm.

"""

import matplotlib.pyplot as plt
import global_variables as gb
import numpy as np
import math

switcher = {
    1: "Heap-Sort",
    2: "Cocktail-Sort",
    3: "Shell-Sort"
} # End dictionary.

function = ""

def initialize ( ):
    # Parameters S ( n ) -size-.
    s_1 = list ( map ( lambda x:x [ 0 ], gb.parameters_1 ) )
    s_2 = list ( map ( lambda x:x [ 0 ], gb.parameters_2 ) )
    s_3 = list ( map ( lambda x:x [ 0 ], gb.parameters_3 ) )
    # Parameters T ( t ) -time-.
    t_1 = list ( map ( lambda x:x [ 1 ], gb.parameters_1 ) )
    t_2 = list ( map ( lambda x:x [ 1 ], gb.parameters_2 ) )
    t_3 = list ( map ( lambda x:x [ 1 ], gb.parameters_3 ) )
    # Proposed functions.
    p_1 = list ( map ( lambda x: ( 10/8 ) * x, t_1 ) )
    p_2 = list ( map ( lambda x: ( 10/8 ) * x, t_2 ) )
    p_3 = list ( map ( lambda x: ( 10/8 ) * x, t_3 ) )
    # Return statement.
    return s_1, s_2, s_3, t_1, t_2, t_3, p_1, p_2, p_3

def plot ( algorithm ):
    # Initialize the plot points.
    s_1, s_2, s_3, t_1, t_2, t_3, p_1, p_2, p_3 = initialize ( )
    # Window title.
    plt.figure ( "Maximum Subarray Problem", figsize = ( 14, 7 ) )

    # BRUTE-FORCE MAXIMUM SUBARRAY ALGORITHM PLOT.

    plt.subplot ( 1, 3, 1 )
    # Figure title.
    plt.title ( "Best case: {} ( {}, {} )".format ( switcher [ algorithm ], gb.parameters_1 [ -1 ] [ 0 ], gb.parameters_1 [ -1 ] [ 1 ] ), size = "small" )
    plt.ylabel ( "Time ( t )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    plt.plot ( s_1, p_1, "#000000", linestyle = "--", label = "" )
    plt.plot ( s_1, t_1, "#0B3B0B", linewidth = 3, label = "" )
    plt.legend ( loc = "upper left" )

    # MAXIMUM CROSSING SUBARRAY ALGORITHM PLOT.

    plt.subplot ( 1, 3, 2 )
    # Figure title.
    plt.title ( "Random case: {} ( {}, {} )".format ( switcher [ algorithm ], gb.parameters_2 [ -1 ] [ 0 ], gb.parameters_2 [ -1 ] [ 1 ] ), size = "small" )
    plt.xlabel ( "Size ( n )", color = ( 0.3, 0.4, 0.6 ), family = "cursive", size = "large" )
    plt.plot ( s_2, p_2, "#000000", linestyle = "--", label = "" )
    plt.plot ( s_2, t_2, "#610B0B", linewidth = 3, label = "" )
    plt.legend ( loc = "upper left" )

    # MAXIMUM SUBARRAY RECURENCE ALGORITHM PLOT.

    plt.subplot ( 1, 3, 3 )
    # Figure title.
    plt.title ( "Worst case: {} ( {}, {} )".format ( switcher [ algorithm ], gb.parameters_3 [ -1 ] [ 0 ], gb.parameters_3 [ -1 ] [ 1 ] ), size = "small" )
    plt.plot ( s_3, p_3, "#000000", linestyle = "--", label = "" )
    plt.plot ( s_3, t_3, "#4C0B5F", linewidth = 3, label = "" )
    plt.legend ( loc = "upper left" )

    plt.show ( )
