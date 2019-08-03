def fibonacci ( n, count ):
    count += 1
    if ( n == 1 or n == 2 ):
        return 1, count
    else:
        a, count = fibonacci ( n - 1, count )
        b, count = fibonacci ( n - 2, count )
        return a + b, count
