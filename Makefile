CC = gcc
CFLAGS = -c -Wall
LDFLAGS = -lncurses

SOURCES = langton.c visualiser.c
OBJECTS = $(SOURCES:.c=.o)

all: $(SOURCES) ant

ant: $(OBJECTS) main.c
	$(CC) -o ant main.c $(OBJECTS) $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) ant

#run make clean to remove any executables on a failed compilation