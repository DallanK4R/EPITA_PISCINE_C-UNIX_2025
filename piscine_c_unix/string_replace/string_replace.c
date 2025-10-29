#include "string_replace.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int ln(const char *s)
{
    if (!s)
        return 0;
    int i = 0;
    while (s[i])
        i++;
    return i;
}

int hm(char c, const char *s)
{
    if (!s)
        return 0;
    int i = 0;
    int cpt = 0;
    while (s[i])
    {
        if (s[i] == c)
            cpt++;
        i++;
    }
    return cpt;
}

char *string_replace(char c, const char *str, const char *pattern)
{
    if (str == NULL)
        return NULL;
    char *res = calloc(ln(str) - hm(c, str) + hm(c, str) * ln(pattern) + 1, 1);
    int i = 0;
    int k = 0;
    while (str[i])
    {
        if (str[i] == c)
        {
            if (pattern != NULL)
            {
                int t = 0;
                while (pattern != NULL && pattern[t])
                {
                    res[k++] = pattern[t++];
                }
            }
        }
        else
        {
            res[k++] = str[i];
        }
        i++;
    }
    return res;
}
