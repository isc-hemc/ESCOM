run: a.out
	./a.out

main.o: main.c
	gcc -c main.c -Wall

Linked_List.o: Linked_List.c
	gcc -c Linked_List.c -Wall

clean:
	rm main.o Linked_List.o

a.out: main.o Linked_List.o
	gcc main.o Linked_List.o
