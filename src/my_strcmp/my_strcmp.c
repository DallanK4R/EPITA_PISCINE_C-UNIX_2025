#include "my_strcmp.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] != 0 && s2[i] != 0)
    {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
        i++;
    }
    return s1[i] - s2[i];
}
