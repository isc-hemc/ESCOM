run: a.out
	./a.out

Main.o: Main.c
	gcc -c Main.c -Wall

Menu.o: Menu.c
	gcc -c Menu.c -Wall

ThreadProduct.o: ThreadProduct.c
	gcc -c ThreadProduct.c -Wall

ConstructMatrix.o: ConstructMatrix.c
	gcc -c ConstructMatrix.c -Wall

a.out: Main.o Menu.o ThreadProduct.o ConstructMatrix.c
	gcc Main.o Menu.o ConstructMatrix.c ThreadProduct.o -pthread

clean:
	rm Main.o Menu.o ConstructMatrix.o ThreadProduct.o x
