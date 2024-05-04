.PHONY: all, clear

CC = gcc
FLAGS = -Wall -Wextra
SDLib = `sdl2-config --cflags --libs`

all: main.o
	./main.o

main.o : main.c
	$(CC) main.c -o main.o $(FLAGS) $(SDLib)

clear:
	rm -rf *.o