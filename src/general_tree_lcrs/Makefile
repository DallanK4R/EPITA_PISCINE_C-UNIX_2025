CC=gcc
CFLAGS= -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

library: gtree.o print.o serialize.o
	ar rcs libgtree.a gtree.o print.o serialize.o
clean:
	$(RM) gtree.o print.o serialize.o libgtree.a
