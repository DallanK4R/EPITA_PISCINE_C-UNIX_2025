#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int *add_int_ptr(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return a;
    *a = *a + *b;
    return a;
}
