.PHONY: all clean

CC = gcc
CFLAGS = -DGLEW_STATIC -Wall -Wextra
LDFLAGS = $(shell pkg-config sdl2 glew --cflags --libs --static)

all: main

main: main.o
	./main.o

main.o: main.c
	$(CC) main.c $(CFLAGS) -o main.o $(LDFLAGS) 
	@echo "Compiled main.c"

clean:
	rm -f main main.o
	@echo "Cleanup complete"
