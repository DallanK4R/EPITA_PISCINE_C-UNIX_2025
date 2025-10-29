
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void pointer_swap(int **a, int **b)
{
    int *t = *a;
    *a = *b;
    *b = t;
}
