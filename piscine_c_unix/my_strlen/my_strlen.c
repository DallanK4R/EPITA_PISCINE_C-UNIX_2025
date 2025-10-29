#include "my_strlen.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

size_t my_strlen(const char *s)
{
    size_t k = 0;
    while (*s != 0)
    {
        k++;
        s += 1;
    }
    return k;
}
