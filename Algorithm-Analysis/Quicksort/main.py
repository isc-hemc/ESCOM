from quicksort import quicksort
from graph import graph
from menu import menu
import gb

def main ( ):
    menu ( )
    for i in range ( len ( gb.n ) + 1 ):
        m, gb.time = gb.n [ :i ], 0
        quicksort ( m, 0, len ( m ) - 1 )
        gb.parameters.append ( ( len ( m ), gb.time ) )
    print ( "\n\tSorted list: ", m, "\n" )
    print ( "\n\tQuicksort Parameters: ", gb.parameters )
    print ( "\n\tPartition Parameters: ", gb._parameters )
    graph ( )
main ( )
