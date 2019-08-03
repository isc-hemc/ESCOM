run: a.out
	./a.out

Main.o: Main.c
	gcc -c Main.c -Wall

ConstructMatrix.o: ConstructMatrix.c
	gcc -c ConstructMatrix.c -Wall

Process.o: Process.c
	gcc -c Process.c -Wall

MatrixProduct.o: MatrixProduct.c
	gcc -c MatrixProduct.c -Wall

MemoryAssignment.o: MemoryAssignment.c
	gcc -c MemoryAssignment.c -Wall

a.out: Main.o ConstructMatrix.o Process.o MatrixProduct.o MemoryAssignment.o
	gcc Main.o ConstructMatrix.o Process.o MatrixProduct.o MemoryAssignment.o

clean:
	rm Main.o ConstructMatrix.o MemoryAssignment.o Process.o MatrixProduct.o
