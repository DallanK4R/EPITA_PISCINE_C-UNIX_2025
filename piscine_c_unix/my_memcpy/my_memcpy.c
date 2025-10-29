#include "my_memcpy.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void *my_memcpy(void *dest, const void *src, size_t n)
{
    const char *s = src;
    char *d = dest;
    for (size_t i = 0; i < n; i++)
    {
        d[i] = s[i];
    }
    return d;
}
