CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla -fsanitize=address

all:sieve.o

sieve.o: sieve.c
	$(CC) $(CFLAGS) -c sieve.c -o sieve.o
