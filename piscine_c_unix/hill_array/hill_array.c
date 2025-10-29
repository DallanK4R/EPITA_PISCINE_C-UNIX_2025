#include "hill_array.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int top_of_the_hill(int tab[], size_t len)
{
    int ct = 0;
    if (len == 1)
        return 0;
    for (size_t o = 0; o < len; o++)
    {
        if (tab[o] < 0)
            return -1;
    }
    size_t i = 0;
    while (tab[i] <= tab[i + 1])
    {
        if (tab[i] < tab[i + 1])
            ct = i + 1;
        if (i == len - 2)
            return ct;
        i++;
    }
    while (tab[i] >= tab[i + 1])
    {
        if (i == len - 2)
            return ct;
        i++;
    }
    return -1;
}
