# Daniel Velazquez
# January 2016 - AFCS Compiler
CCC= gcc

CFLAGS = -c -Wall $(shell pkg-config --cflags opencv -lgobject-2.0)
LDFLAGS = $(shell pkg-config --libs --static opencv )

all: main

main: main.o mesh.o improc.o
	$(CC) -o $@ main.o mesh.o improc.o $(LDFLAGS)

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c $(LDFLAGS)
mesh.o: mesh.c
	$(CC) $(CFLAGS) -c mesh.c $(LDFLAGS)	
improc.o: improc.c
	$(CC) $(CFLAGS) -c improc.c $(LDFLAGS)	


#clean: ; rm -f main.o main
