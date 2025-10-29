CC=gcc
CFLAGS= -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

library: dlist_tr1.o dlist_tr2.o dlist_tr3.o dlist_tr4.o dlist_tr5.o dlist_tr6.o
	ar rcs libdlist.a dlist_tr1.o dlist_tr2.o dlist_tr3.o dlist_tr4.o dlist_tr5.o dlist_tr6.o
clean:
	$(RM) dlist_tr1.o dlist_tr2.o dlist_tr3.o dlist_tr4.o dlist_tr5.o dlist_tr6.o libdlist.a
