CC=gcc
CFLAGS= -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

library: add.o create.o del.o pop.o print.o
	ar rcs libheap.a add.o create.o del.o pop.o print.o
clean:
	$(RM) add.o create.o del.o pop.o print.o libheap.a
