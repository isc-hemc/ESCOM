run: a.out
	./a.out

main.o: main.c
	gcc -c main.c -Wall

Tree.o: Tree.c
	gcc -c Tree.c -Wall

a.out: main.o Tree.o
	gcc main.o Tree.o
