#include "my_memcmp.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    const char *j1 = s1;
    const char *j2 = s2;
    int k = 0;
    for (size_t i = 0; i < num; i++)
    {
        k += j1[i] - j2[i];
    }
    return k;
}
