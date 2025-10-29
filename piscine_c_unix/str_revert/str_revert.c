#include "str_revert.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void str_revert(char str[])
{
    int i = 0;
    while (str[i] != 0)
    {
        i++;
    }
    i -= 1;
    for (int k = 0; k < i / 2 + 1; k++)
    {
        char o = str[k];
        str[k] = str[i - k];
        str[i - k] = o;
    }
}
