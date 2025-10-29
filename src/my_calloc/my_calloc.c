#include "my_calloc.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_calloc(size_t n, size_t size)
{
    char *res = malloc(n * size);
    for (size_t i = 0; i < n * size; i++)
    {
        res[i] = 0;
    }
    return res;
}
