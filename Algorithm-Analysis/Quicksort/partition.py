import gb

def partition ( n, p, r ):
    x = n [ r ] # pivot
    gb._time += 1
    i = p # border
    gb._time += 1
    for j in range ( p, r ):
        gb._time += 1
        if ( n [ j ] < x ):
            aux = n [ j ]
            gb._time += 1
            n [ j ] = n [ i ]
            gb._time += 1
            n [ i ] = aux
            gb._time += 1
            i += 1
            gb._time += 1
    gb._time += 1
    aux = n [ i ]
    gb._time += 1
    n [ i ] = n [ r ]
    gb._time += 1
    n [ r ] = aux
    gb._time += 1
    # Sum the temporal complexity of Partition '_time' to the temporal
    # complexity of Quicksort 'time'.
    gb.time += gb._time
    if ( r > gb._parameters [ len ( gb._parameters ) - 1 ][ 0 ] ):
        gb._parameters.append ( ( r, gb._time ) )
    gb._time = 0
    return i
