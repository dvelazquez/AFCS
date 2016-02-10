# Daniel Velazquez
# January 2016 - AFCS Compiler
CC= gcc
MvBin= mv AFCS.bin bin/AFCS.bin
MvObj= mv *.o obj


CFLAGS = -c -Wall $(shell pkg-config --cflags opencv -lgobject-2.0)
LDFLAGS = $(shell pkg-config --libs --static opencv )

all: AFCS.bin

AFCS.bin: main.o Initialization.o Mesh.o ImageProcessing.o
	$(CC) -o $@ main.o Initialization.o Mesh.o ImageProcessing.o $(LDFLAGS)
	$(MvObj)
	$(MvBin)

main.o: src/main.c 
	$(CC) $(CFLAGS) -c src/main.c $(LDFLAGS)

Mesh.o: src/Mesh.c
	$(CC) $(CFLAGS) -c src/Mesh.c $(LDFLAGS)	

ImageProcessing.o: src/ImageProcessing.c
	$(CC) $(CFLAGS) -c src/ImageProcessing.c $(LDFLAGS)

Initialization.o: src/Initialization.c
	$(CC) $(CFLAGS) -c src/Initialization.c $(LDFLAGS)		

#clean: ; rm -f main.o main
