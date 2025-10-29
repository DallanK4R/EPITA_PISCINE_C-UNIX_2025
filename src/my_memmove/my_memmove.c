#include "my_memmove.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void *my_memmove(void *dest, const void *src, size_t n)
{
    size_t i = 0;
    char *d = dest;
    const char *s = src;
    if (src > dest)
    {
        while (i < n)
        {
            if (s[i] != d[i])
            {
                d[i] = s[i];
            }
            i++;
        }
    }
    else
    {
        while (i < n)
        {
            if (s[n - i - 1] != d[n - i - 1])
            {
                d[n - i - 1] = s[n - i - 1];
            }
            i++;
        }
    }
    return d;
}
