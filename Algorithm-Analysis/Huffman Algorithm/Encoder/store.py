"""

ALGORITHM ANALYSIS:

Python File: store.py

Date: Tue November 21 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: Stores in differents files the information obtained in Huffman's
             algorithm process.

"""

import pickle
import json

def store ( compressed, frequency, probability, dictionary ):
    # Stores the encoded sequence in a binary file.
    with ( open ( "Files/Encoded File.txt", "wb" ) ) as f:
        pickle.dump ( compressed, f )
    # Stores the Frequency that the symbols appeared.
    with ( open ( "Files/Frequency.txt", "w" ) ) as f:
        f.write ( "\n\t\t{0:10} {1:15} {2:10}\n\t\t"
                  .format ( "Symbol", "Probability", "Frequency" ) )
        for symbol in frequency:
            f.write ( "{0:10} {1:15.6} {2:10}\n\t\t"
                      .format ( symbol, str ( probability [ symbol ] ),
                                        str ( frequency [ symbol ] ) ) )
    # Stores the Codification of each symbol.
    with ( open ( "Files/Codification.txt", "w" ) ) as f:
        f.write ( "\n\t\t{0:10} {1:10}\n\t\t"
                  .format ( "Symbol", "Codes" ) )
        for symbol in dictionary:
            f.write ( "{0:10} {1:10}\n\t\t"
                      .format ( symbol, dictionary [ symbol ] ) )
    # Stores the dictionary with the coding of each symbol.
    with ( open ( "Files/Dictionary.dic", "w" ) ) as f:
        json.dump ( dictionary, f )
