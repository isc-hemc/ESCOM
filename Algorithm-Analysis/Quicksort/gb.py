"""
                                GLOBAL VARIABLES MODULES

    _parameters: List that store the parameters of the points to plot for Partition. Each element
                 it's a tuple that stores the length of the sorted list, and the time that the al-
                 gorithm took to execute its process the first time it was called.

    parameters: List that store the parameters of the points to plot for Quicksort. Each element
                it's a tuple that stores the length of the sorted list, and the time that the
                algorithm takes to sort it.

    _time: Counter that stores the computational time that the algorithm Partition takes to
           finish his execution process.

    time: Counter that stores the computational time that the algorithm Quicksort takes to
          sort the list 'n'.

    flag: Flag used in graph.py, help to create the labels of the proposed function, depending
          if the user select worst or random case.

    n: List to sort.

"""

_parameters = [ ( 0, 6 )]
parameters = [ ]
flag = False
_time = 0
time = 0
n = [ ]
