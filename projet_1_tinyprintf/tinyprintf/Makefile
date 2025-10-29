CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla
TESTFLAGS = -fsanitize=address -lcriterion

all: src/tinyprintf.o

src/tinyprintf.o:
	$(CC) $(CFLAGS) -c src/tinyprintf.c -o src/tinyprintf.o

check:
	$(CC) $(CFLAGS) src/tinyprintf.c tests/main.c $(TESTFLAGS) -o testsuite
	./testsuite

clean:
	$(RM) src/tinyprintf.o testsuite

