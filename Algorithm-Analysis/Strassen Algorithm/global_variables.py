"""

ALGORITHM ANALYSIS:

Python File: main.py

Date: Tue October 10 20:03:00 2017

Credits: Hernandez Martinez Carlos David.
         Burciaga Ornelas Rodrigo Andres.

Email: davestring@outlook.com.
       andii_burciaga@live.com.

Description: This module only stores the global variables of the program:

        parameters: List that store the parameters of the points to plot for Strassen´s
                    Algorithm. Each element it's a tuple that stores the length of the
                    matrices, and the time that the algorithm takes to calculate the product.

        time: Counter that stores the computational time that Strassen´s Algorithm takes to
              calculate the product of two matrices.

        _parameters: List that store the parameters of the points to plot for ijk-Algorithm Each
                     element it's a tuple that stores the length of the matrices, and the time that
                     the algorithm takes to calculate the product.

        _time: Counter that stores the computational time that the ijk-Algorithm takes to calculate
               the product of two matrices.

        Flag: Stores a boolean, is used in plot.py, if the matrices size are bigger or equal than 2^8
              then, Flag will take the value of "true" and the program will compare the complexity of
              the Strassen's algorithm against the usual matrix product ( ijk algorithm ).

"""

_parameters = [ ]
parameters = [ ]
flag = False
_time = 0
time = 0
