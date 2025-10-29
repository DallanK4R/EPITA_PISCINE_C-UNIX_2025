#include "bsearch.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int *binary_search(int *begin, int *end, int elt)
{
    while (begin < end)
    {
        int *mid = begin + (end - begin) / 2;

        if (*mid == elt)
            return mid;
        else if (*mid < elt)
            begin = mid + 1;
        else
            end = mid;
    }
    return begin;
}
