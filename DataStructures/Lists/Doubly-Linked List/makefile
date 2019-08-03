run: a.out
	./a.out

main.o: main.c
	gcc -c main.c -Wall

Doubly-Linked_List.o: Doubly-Linked_List.c
	gcc -c Doubly-Linked_List.c -Wall

clean:
	rm main.o Doubly-Linked_List.o

a.out: main.o Doubly-Linked_List.o
	gcc main.o Doubly-Linked_List.o
