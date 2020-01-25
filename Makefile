CC=gcc
OBJECTS_MAIN=main.o
OBJECTS_LIB=frequency.o 
FLAGS= -Wall -g

all: frequency	

frequency: main.o frequency.o
	$(CC) $(FLAGS) -o frequency main.o frequency.o

frequency.o: frequency.c frequency.h
	$(CC) $(FLAGS) -c frequency.c
main.o: main.c frequency.h  
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o frequency