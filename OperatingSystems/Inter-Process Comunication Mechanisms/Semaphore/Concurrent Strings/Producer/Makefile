run: a.out
	./a.out

Producer.o: Producer.c
	gcc -c Producer.c -Wall

Initialize.o: Initialize.c
	gcc -c Initialize.c -Wall

Threads.o: Threads.c
	gcc -c Threads.c -Wall

Wait.o: Wait.c
	gcc -c Wait.c -Wall

Signal.o: Signal.c
	gcc -c Signal.c -Wall

a.out: Producer.o Initialize.o Threads.o Wait.o Signal.o
	gcc Producer.o Initialize.o Threads.o Wait.o Signal.o
