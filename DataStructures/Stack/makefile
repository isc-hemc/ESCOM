run: a.out
	./a.out

main.o: main.c
	gcc -c main.c -Wall

stack.o: stack.c
	gcc -c stack.c -Wall

clean:
	rm main.o stack.o

a.out: main.o stack.o
	gcc main.o stack.o
