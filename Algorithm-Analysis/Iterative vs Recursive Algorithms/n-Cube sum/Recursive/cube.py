def cube ( n, count ):
    count += 1
    if ( n == 1 ):
        return 1, count
    else:
        a, count = cube ( n - 1, count )
        b = n*n*n
        return a + b, count
