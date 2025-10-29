#include "my_strtok_r.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int cheking(char *str, const char *delim)
{
    int k = 0;
    int isdelim = 0;
    while (str[k] != 0)
    {
        int o = 0;
        while (delim[o] != 0)
        {
            isdelim = 0;
            if (str[k] == delim[o])
            {
                isdelim = 1;
                break;
            }
            o++;
        }
        if (isdelim == 0)
            break;
        k++;
    }
    return k;
}
char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    if (str == NULL)
        str = *saveptr;
    if (*str == 0)
        return NULL;
    int k = cheking(str, delim);
    if (str[k] == 0)
        return NULL;
    char *tokenstart = str + k;
    int i = k;
    while (str[i] != 0)
    {
        int j = 0;
        while (delim[j] != 0)
        {
            if (str[i] == delim[j])
            {
                str[i] = 0;
                *saveptr = str + i + 1;
                return tokenstart;
            }
            j++;
        }
        i++;
    }
    *saveptr = str + i;
    return tokenstart;
}
