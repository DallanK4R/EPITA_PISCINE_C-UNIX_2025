#include "element_count.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

size_t element_count(int *begin, int *end)
{
    size_t cpt = 0;
    while (begin != end)
    {
        begin += 1;
        cpt++;
    }
    return cpt;
}
