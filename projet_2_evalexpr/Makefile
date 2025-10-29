CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

SRCS = src/fifo.c src/main.c src/stack.c src/evalexpr.c src/precedence.c src/utils.c src/utils2.c
OBJS = ${SRCS:.c=.o}

TARGET = evalexpr


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): $(SRCS)

check:
	./tests/tests.sh

#coverage: CFLAGS += -lgcov -fPIC --coverage
#coverage: LDFLAGS += -lgcov -fPIC --coverage
#coverage: $(TARGET)
#	./tests/tests.sh
#	gcovr --html --html-details --output=report.html

clean:
	$(RM) $(OBJS) debug testsuite $(TARGET)
