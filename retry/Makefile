CC = gcc
CFLAGS = -c -Wall
LDFLAGS = -lncurses

SOURCES = langton.c visualiser.c
OBJECTS = $(SOURCES:.c=.o)

all: $(SOURCES) ant library
	./ant 
	
ant: $(OBJECTS) main.c
	$(CC) -o ant main.c $(OBJECTS) $(LDFLAGS)

library: $(OBJECTS)
	$(CC) -o libant.so $(OBJECTS) -shared $(CFLAGS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -rf $(OBJECTS) ant

#run make clean to remove any executables on a failed compilation