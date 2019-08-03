def cube ( n ):
    if ( n == 1 ):
        return 1
    else:
        return cube ( n - 1 ) + n*n*n
