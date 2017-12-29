CC = gcc
CFLAGS = -I. -g3
OBJ = main.o memory_manager_test.o
SRC_OBJ = memory_manager.o

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

UnitTests: make_sources $(OBJ)
	gcc -Wall -L/usr/lib/x86_64-linux-gnu -o UnitTests $(OBJ) $(SRC_OBJ) -lcunit
	
.ONESHELL:
make_sources:
	cd ../../src
	make
	cp $(SRC_OBJ) ../tests/UnitTests

clean:
	rm UnitTests $(OBJ) $(SRC_OBJ)
		
.PHONY: clean make_sources
