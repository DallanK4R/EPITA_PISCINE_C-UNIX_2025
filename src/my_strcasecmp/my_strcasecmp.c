#include "my_strcasecmp.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int caseign(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int my_strcasecmp(const char *s1, const char *s2)
{
    int total = 0;
    int i = 0;
    while (s1[i] && s2[i])
    {
        total += caseign(s1[i]) - caseign(s2[i]);
        i++;
    }
    if (s1[i])
    {
        while (s1[i])
        {
            total += caseign(s1[i]);
            i++;
        }
    }
    else
    {
        while (s2[i])
        {
            total -= caseign(s2[i]);
            i++;
        }
    }
    return total;
}
