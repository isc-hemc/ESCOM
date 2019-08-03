# Fibonacci Generator.
def fibonacci ( ):
    a, b = 1, 1
    while ( True ):
        yield a
        a, b = b, a + b

# Fibonacci list.
def fibolist ( limit ):
    n, fibo = 0, [ ]
    # Create a Fibonacci numbers list using a generator.
    for i in fibonacci ( ):
        if ( n >= limit ): break
        fibo.append ( i )
        n += 1
    # Return statement.
    return fibo
