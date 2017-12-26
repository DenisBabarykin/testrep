CC = gcc
CFLAGS = -I. -Wall -Werror -g
DEPS = hello.h
OBJ = main.o hello.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

server: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean:
	-rm server $(OBJ)
		
.PHONY: clean