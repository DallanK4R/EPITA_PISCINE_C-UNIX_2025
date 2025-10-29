CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

main: main.o
	$(CC) -o $@ $^

debug: CFLAGS +=-fsanitize=address -g
debug: LDFLAGS += -fsanitize=address
debug: main.o
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) main main.o debug
