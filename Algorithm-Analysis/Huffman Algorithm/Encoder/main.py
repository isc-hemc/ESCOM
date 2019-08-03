"""

ALGORITHM ANALYSIS:

Python File: main.py

Date: Tue November 21 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: Implements the __main__ method and gets the input text.

"""

from collections import Counter
from Huffman import *
from store import *

TEST = "This is a test for Huffman's algorithm."

def getText ( ):
    with ( open ( "Files/Original.txt", "r" ) ) as f:
        txtin = f.read ( ).rstrip ( "\n" )
        content = TEST if ( txtin == "" ) else txtin
    return content

def main ( ):
    txtin = getText ( )
    huffman = Huffman ( txtin )
    huffman.setFrequency ( )
    huffman.setTree ( )
    huffman.setCodes ( )
    huffman.encode ( )
    store ( huffman.result, huffman.frequency, huffman.probability, huffman.codes )

if ( __name__ == "__main__" ):
    main ( )
