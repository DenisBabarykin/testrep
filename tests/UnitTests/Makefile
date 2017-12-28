CC = gcc
CFLAGS = -I. -Wall -Werror -g3
OBJ = main.o hello_test.o
SRC_OBJ = hello.o

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
