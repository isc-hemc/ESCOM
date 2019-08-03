"""

ALGORITHM ANALYSIS:

Python File: decode.py

Date: Tue November 21 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: Implements the algorithm that decodes a Huffman's algorithm output.

"""

def decode ( dictionary, binary ):
    result = [ ]
    length = binary.bit_length ( ) - 1
    # First character must be 1, otherwise there is an error.
    if ( binary >> length != 1 ):
        raise ( "Error: Corrupt file." )
    done = False
    while ( length > 0 and ( not done ) ):
        shift = length - 1
        # Increase bit by bit.
        while ( True ):
            num = binary >> shift
            # Delete the initial '1' and the '0b' of the format.
            bitnum = bin ( num ) [ 3: ]
            if ( bitnum not in dictionary ):
                shift -= 1
                continue
            char = dictionary [ bitnum ]
            if ( char == "end" ):
                done = True
                break
            result.append ( char )
            binary = binary - ( ( num - 1 ) << shift )
            length = shift
    return "".join ( result )
