CC=gcc
CFLAGS= -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

library: binary_tree_dynamic.o
	ar rcs libbinary_tree.a binary_tree_dynamic.o
clean:
	$(RM) binary_tree_dynamic.o libbinary_tree.a
