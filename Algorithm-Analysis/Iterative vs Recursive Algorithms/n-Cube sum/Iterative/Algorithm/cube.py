def cube ( n ):
    _sum= 0
    # Range: From 1 <= i <= n.
    for i in range ( 1, n + 1 ):
        _sum = _sum + ( i * i * i )
    # Return statement.
    return _sum
