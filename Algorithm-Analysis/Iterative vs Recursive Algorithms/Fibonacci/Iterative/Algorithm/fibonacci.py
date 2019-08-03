def fibonacci ( n ):
    fibo, a, b = 1, 1, 0
    for i in range ( 1, n ):
        fibo = a + b
        b = a
        a = fibo
    return fibo
