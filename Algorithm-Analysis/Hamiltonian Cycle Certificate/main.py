"""

ALGORITHM ANALYSIS:

Python File: main.py

Date: Tue November 28 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: Implements the __main__ method and contains a function named printer
             that displays in console output, as well a method that verify if the
             given certificate it's a Hamiltonian-cycle of G.
"""

import plot as plt
import gb

def printer ( flag, C ):
    if ( flag == -1 ):
        print ( "\n\n\tThe certificate {} isn't a Hamiltonian Cycle.\n".format ( C ) )
        exit ( 0 )
    print ( "\n\n\tThe certificate {} is a Hamiltonian Cycle.\n".format ( C ) )

def verify_hamiltonian ( graph, certificate ):
    gb.time += 1
    for i in range ( len ( graph ) ):
        gb.time += 1
        neighbors = graph [ certificate [ i ] ]
        gb.time += 1
        if ( certificate [ i + 1 ] not in neighbors ):
            printer ( -1, certificate )
        gb.parameters.append ( ( len ( certificate [ : i ] ), gb.time + neighbors.index ( certificate [ i + 1 ] ) + 1 ) )
    printer ( 0, certificate )
    print ( gb.parameters )

def main ( ):
    graph = { 1: [ 2, 4, 8 ], 2: [ 7, 3, 1 ], 3: [ 2, 6, 4 ],
              4: [ 1, 3, 5 ], 5: [ 4, 8, 6 ], 6: [ 5, 3, 7 ],
              7: [ 6, 2, 8 ], 8: [ 7, 5, 1 ] }
    certificate = [ 1, 2, 3, 4, 5, 6, 7, 7, 1 ]
    verify_hamiltonian ( graph, certificate )
    plt.plot ( )

if ( __name__ == "__main__" ):
    main ( )
