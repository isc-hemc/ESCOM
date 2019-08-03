"""

ALGORITHM ANALYSIS:

Python File: maximum_subarray.py

Date: Tue October 17 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: Implementation of maximum subarray algorithms:

    · Brute-Force Maximum Subarray.

    · Maximum Crossing Subarray.

    · Maximum Recurrence Subarray.

"""

import global_variables as gb

def brute_force ( A ):
    gb.time += 1
    sums = [ 0 ]
    gb.time += 1
    for i in A:
        gb.time += 1
        sums.append ( sums [ -1 ] + i )
        gb.time += 1
    gb.time += 1
    max_sum = int ( -1e100 )
    gb.time += 1
    left_index = -1
    gb.time += 1
    right_index = -1
    gb.time += 1
    for i in range ( len ( A ) ):
        gb.time += 1
        for j in range ( i, len ( A ) ):
            gb.time += 1
            if ( sums [ j + 1 ] - sums [ i ] > max_sum ):
                gb.time += 1
                max_sum = sums [ j + 1 ] - sums [ i ]
                gb.time += 1
                left_index = i
                gb.time += 1
                right_index = j
                gb.time += 1
            gb.time += 1
        gb.time += 1
    # Return statement.
    gb.time += 1
    return left_index, right_index, max_sum

def crossing ( A, low, mid, high ):
    gb.time += 1
    max_left, max_right = 0, 0
    gb.time += 1
    left_sum = int ( -1e100 )
    gb.time += 1
    _sum = 0
    gb.time += 1
    for i in range ( mid - 1, low - 1, -1 ):
        gb.time += 1
        _sum = _sum + A [ i ]
        gb.time += 1
        if ( _sum > left_sum ):
            gb.time += 1
            left_sum = _sum
            gb.time += 1
            max_left = i
        gb.time += 1

    gb.time += 1
    right_sum = int ( -1e100 )
    gb.time += 1
    _sum = 0
    gb.time += 1
    for i in range ( mid, high ):
        gb.time += 1
        _sum = _sum + A [ i ]
        gb.time += 1
        if ( _sum > right_sum ):
            gb.time += 1
            right_sum = _sum
            gb.time += 1
            max_right = i
        gb.time += 1
    # Return statement.
    gb.time += 1
    return max_left, max_right, right_sum + left_sum

def recurrence ( A, low, high ):
    gb.time += 1
    if ( high == low + 1 ):
        gb.time += 1
        return low, high, A [ low ]
    else:
        gb.time += 1
        mid = int ( ( low + high ) / 2 )
        gb.time += 1
        left_low, left_high, left_sum = recurrence ( A, low, mid )
        gb.time += 1
        right_low, right_high, right_sum = recurrence ( A, mid, high )
        gb.time += 1
        cross_low, cross_high, cross_sum = crossing ( A, low, mid, high )
        gb.time += 1
        if ( left_sum >= right_sum and left_sum >= cross_sum ):
            gb.time += 1
            return left_low, left_high, left_sum
        elif ( right_sum >= left_sum and right_sum >= cross_sum ):
            gb.time += 1
            return right_low, right_high, right_sum
        else:
            gb.time += 1
            return cross_low, cross_high, cross_sum
