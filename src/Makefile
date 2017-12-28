CC = gcc
CFLAGS = -I. -Wall -Werror -g3
OBJ = main.o memory_manager.o

%.o: %.c *.h
	$(CC) -c -o $@ $< $(CFLAGS)

server: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm server $(OBJ)
		
.PHONY: clean
