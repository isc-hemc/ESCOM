def binarysum ( a, b ):
    i, carry, c, count = ( len ( a ) - 1 ), 0, [ ], 1
    # Evaluate both binary lists ( 'a' and 'b' ) and scroll through from ( n - 1 ) to 0
    # and sum the numbers at 'i' position, the result is stored in 'c'.
    while ( i >= 0 ):
        count += 1
        if ( ( a [ i ] + b [ i ] + carry ) == 1 ):
            count += 1
            c.insert ( 0, 1 )
            count += 1
            carry = 0
            count += 1
        elif ( ( a [ i ] + b [ i ] + carry ) == 2 ):
            count += 1
            c.insert ( 0, 0 )
            count += 1
            carry = 1
            count += 1
        elif ( ( a [ i ] + b [ i ] + carry ) == 3 ):
            count += 1
            c.insert ( 0, 1 )
            count += 1
            carry = 1
            count += 1
        else:
            count += 1
            c.insert ( 0, 0 )
            count += 1
            carry = 0
            count += 1
        i = i - 1
        count += 1
    count += 1
    # After finish, evaluates if there is a carry value.
    count += 1
    if ( carry == 1 ):
        c.insert ( 0, carry )
        count += 1
    # Return statement.
    return c, count
