def algorithm ( n, m ):
    # Euclidean algorithm: Find the Greatest Common Divisor ( gcd ).
    count, gcd = 1, [ ]
    while ( m != 0 ):
        gcd.append ( n )
        count += 1
        r = n % m
        count += 1
        n = m
        count += 1
        m = r
        count += 1
    count += 1
    # return statement.
    return n, count, gcd
