#makefile for the coursework it will feature the files visualiser.c and .h and langton.c and .h as well as main.c

#define the compiler
CC=gcc
#define the flags to be used when compiling -c is so the compiler doesn't compile main straight away -wall raises compiler errors fully
#-werror stops the compilation at an error and -i. makes sure libraries are being defined
CFLAGS=-c -Wall -Werror -I.
LDFLAGS=-lncursesw
SOURCES=main.c langton.c visualiser.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=myprogram

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
#run make clean to remove any executables on a failed compilation