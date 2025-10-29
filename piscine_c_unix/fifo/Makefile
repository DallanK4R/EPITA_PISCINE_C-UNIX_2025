CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

all: fifo.o

sieve.o: fifo.c
	$(CC) $(CFLAGS) -c fifo.c -o fifo.o

clean:
	rm -f fifo.o

