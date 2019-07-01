#declare the variableble
CC=g++

CFLAGS=-c -Wall

all: output
	
output: main.o 
        $(CC) main.o -o output

main.o: main.cpp
        $(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *o output
