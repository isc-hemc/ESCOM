"""

ALGORITHM ANALYSIS:

Python File: main.py

Date: Tue November 21 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: Implements the __main__ method and gets the input parameters for
             decoding.

"""

from decode import *
import pickle
import ast

def getParameters ( ):
    # Get the compressed binary sequence.
    compressed = pickle.load ( open ( "../Encoder/Files/Encoded File.txt", "rb" ) )
    # Get the dictionary with the coding of each symbol.
    f = open ( "../Encoder/Files/Dictionary.dic", "r" )
    dictionary = f.read ( )
    dictionary = ast.literal_eval ( dictionary )
    aux = { }
    for key, element in dictionary.items ( ):
        aux [ element ] = key
    f.close ( )
    return compressed, aux

def main ( ):
    compressed, dictionary = getParameters ( )
    decompressed = decode ( dictionary, compressed )
    with ( open ( "Files/Decoded File.txt", "w" ) ) as f:
        f.write ( decompressed )

if ( __name__ == "__main__" ):
    main ( )
