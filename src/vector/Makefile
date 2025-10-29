CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

all: vector.o

sieve.o: vector.c
	$(CC) $(CFLAGS) -c vector.c -o vector.o

clean:
	rm -f vector.o

