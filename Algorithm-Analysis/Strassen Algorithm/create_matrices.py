"""

ALGORITHM ANALYSIS:

Python File: main.py

Date: Tue October 10 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: Creates the matrices A and B.

"""

import random as rnd
import math

def create ( n ):
    # Size of the matrices: 2^n.
    A = [ [ rnd.randint ( 0, 9 ) for i in range ( n ) ] for j in range ( n ) ]
    B = [ [ rnd.randint ( 0, 9 ) for i in range ( n ) ] for j in range ( n ) ]
    return A, B
