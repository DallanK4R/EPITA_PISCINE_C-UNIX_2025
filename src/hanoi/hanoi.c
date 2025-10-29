#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

static void move(unsigned n, int from, int to, int aux)
{
    if (n == 0)
        return;

    move(n - 1, from, aux, to);
    printf("%d->%d\n", from, to);
    move(n - 1, aux, to, from);
}

void hanoi(unsigned n)
{
    move(n, 1, 3, 2);
}
