#include "my_strcpy.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

char *my_strcpy(char *dest, const char *source)
{
    char *start = dest;

    while (*source != 0)
    {
        *start = *source;
        start++;
        source++;
    }

    *start = 0;
    return dest;
}
