#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

void ConstructMatrix ( int counter, int secondCounter );
void Process ( int counter, int secondCounter );
void MatrixProduct ( int counter, int secondCounter, int argument );
void MemoryAssignment ( );

typedef struct MatrixParameters {
  int size;
  int **mainMatrix;
} Matrix;

Matrix Parameters;

int **ProductMatrix;
