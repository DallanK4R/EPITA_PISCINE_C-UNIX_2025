#include "my_itoa.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

char *my_itoa(int value, char *s)
{
    int v = 0;
    if (value < 0)
        v = -value;
    else
        v = value;
    int i = 0;
    int j = v;
    while (j > 10)
    {
        s[i] = (j % 10) + '0';
        j /= 10;
        i++;
    }
    s[i] = (j % 10) + '0';
    i++;
    if (value < 0)
    {
        s[i] = '-';
        i++;
    }
    for (int k = 0; k < i / 2; k++)
    {
        char temp = s[k];
        s[k] = s[i - k - 1];
        s[i - k - 1] = temp;
    }
    s[i] = 0;
    return s;
}
