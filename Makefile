#makefile for the coursework it will feature the files visualiser.c and .h and langton.c and .h as well as main.c

#define the compiler
CC=gcc
#define the flags to be used when compiling -c is so the compiler doesn't compile main straight away -wall raises compiler errors fully
#-werror stops the compilation at an error and -i. makes sure libraries are being defined
CFLAGS = -Wall -I. -fPIC
LDFLAGS = -shared

OBJECTS = visualiser.o langton.o

libant.so: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

ant: libant.so main.c
	$(CC) -L. -lant -o $@ main.c

.PHONY: clean
clean:
	rm -f $(OBJECTS) libant.so ant


#run make clean to remove any executables on a failed compilation