default: prog 

cirListDeque.o: cirListDeque.h cirListDeque.c
	gcc -Wall -std=c99 -c cirListDeque.c

graph.o: graph.h graph.c cirListDeque.o
	gcc -Wall -std=c99 -c graph.c

prog: graph.o cirListDeque.o main.c
	gcc -Wall -std=c99 -o  prog graph.o cirListDeque.o main.c

clean:
	rm cirListDeque.o
	rm graph.o

cleanall: clean
	rm prog 