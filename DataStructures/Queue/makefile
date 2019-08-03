run: a.out
	./a.out

main.o: main.c
	gcc -c main.c -Wall

queue.o: queue.c
	gcc -c queue.c -Wall

clean:
	rm main.o queue.o
	
a.out: main.o queue.o
	gcc main.o queue.o
