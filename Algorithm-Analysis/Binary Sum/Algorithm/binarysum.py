def binarysum ( a, b ):
    i, carry, c = ( len ( a ) - 1 ), 0, [ ]
    # Evaluate both binary lists ( 'a' and 'b' ) and scroll through from ( n - 1 ) to 0
    # and sum the numbers at 'i' position, the result is stored in 'c'.
    while ( i >= 0 ):
        if ( ( a [ i ] + b [ i ] + carry ) == 1 ):
            c.insert ( 0, 1 )
            carry = 0
        elif ( ( a [ i ] + b [ i ] + carry ) == 2 ):
            c.insert ( 0, 0 )
            carry = 1
        elif ( ( a [ i ] + b [ i ] + carry ) == 3 ):
            c.insert ( 0, 1 )
            carry = 1
        else:
            c.insert ( 0, 0 )
            carry = 0
        i = i - 1
    # After finish, evaluates if there is a carry value.
    if ( carry == 1 ):
        c.insert ( 0, carry )
    # Return statement.
    return c, counter
