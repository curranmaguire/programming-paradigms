#makefile for the coursework it will feature the files visualiser.c and .h and langton.c and .h as well as main.c

#define the compiler
#define the flags to be used when compiling -c is so the compiler doesn't compile main straight away -wall raises compiler errors fully
#-werror stops the compilation at an error and -i. makes sure libraries are being defined
CC = gcc
CFLAGS = -c -Wall -fPIC
LDFLAGS = -shared

SOURCES = langton.c visualiser.c main.c
OBJECTS = $(SOURCES:.c=.o)

all: $(SOURCES) ant

ant: $(OBJECTS) main.c libant.so
	$(CC) -o ant main.o -L. -lant $(LDFLAGS)


libant.so: $(OBJECTS)
	$(CC)  $(LDFLAGS)  $(OBJECTS) -lncursesw -o libant.so

.c.o:
	$(CC) $(CFLAGS)  $< -o $@ 

clean:
	rm -rf $(OBJECTS) ant libant.so


#run make clean to remove any executables on a failed compilation