def cube ( n ):
    _sum, count, cubelist = 0, 1, [ ]
    # Range: From 1 <= i <= n.
    for i in range ( 1, n + 1 ):
        count += 1
        _sum = _sum + ( i * i * i )
        count += 1
        cubelist.append ( _sum )
        count += 1
    # Return statement.
    count += 1
    return _sum, count, cubelist
