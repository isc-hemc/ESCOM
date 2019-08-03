def algorithm ( n, m ):
    # Euclidean algorithm: Find the Greatest Common Divisor ( gcd ).
    while ( m != 0 ):
        r = n % m
        n = m
        m = r
    # return statement.
    return n
