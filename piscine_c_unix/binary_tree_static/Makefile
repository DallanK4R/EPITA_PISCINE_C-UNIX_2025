CC=gcc
CFLAGS= -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

library: binary_tree_static2.o binary_tree_static.o
	ar rcs libbinary_tree.a binary_tree_static2.o binary_tree_static.o
clean:
	$(RM) binary_tree_static2.o binary_tree_static.o libbinary_tree.a
