#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void ThreadProduct ( void *argument );
void ConstructMatrix ( int answer );
int Menu ( );

typedef struct MatrixParameters {
    int size;
    int **inputMatrix;
    long *id;
} Matrix;

Matrix Parameters;

int **matrixProduct;
int numberThreads;
int parameterThread;
