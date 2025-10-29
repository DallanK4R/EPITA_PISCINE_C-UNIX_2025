#include "my_strlowcase.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void my_strlowcase(char *str)
{
    while (*str != 0)
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            *str += 32;
        }
        str += 1;
    }
}
