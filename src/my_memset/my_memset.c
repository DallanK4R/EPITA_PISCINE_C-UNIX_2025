#include "my_memset.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void *my_memset(void *s, int c, size_t n)
{
    char *s1 = s;
    for (size_t i = 0; i < n; i++)
    {
        s1[i] = c;
    }
    return s1;
}
