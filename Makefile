#makefile for the coursework it will feature the files visualiser.c and .h and langton.c and .h as well as main.c

all: visualiser.o langton.o main.c 
	gcc -o main.c langton.o visualiser.o -lncursesw
visualiser.o: visualiser.c visualiser.h
	gcc -c visualiser.c

langton.o: langton.c langton.h
	gcc -c langton.c

clean:	
	rm -rf program langton.o visualiser.o