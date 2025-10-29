#include "my_itoa_base.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
static int slen(const char *t)
{
    int k = 0;
    while (t[k] != '\0')
        k++;
    return k;
}

static void reverse_span(char *s, int start, int len)
{
    int i = 0;
    int j = len - 1;

    while (i < j)
    {
        char tmp = s[start + i];
        s[start + i] = s[start + j];
        s[start + j] = tmp;
        i++;
        j--;
    }
}

char *my_itoa_base(int n, char *s, const char *base)
{
    int B = slen(base);
    if (B < 2)
    {
        s[0] = '\0';
        return s;
    }

    long long v = n;
    int neg = 0;

    if (B == 10 && v < 0)
    {
        neg = 1;
        v = -v;
    }

    int i = 0;
    if (neg)
        i = 1;

    if (v == 0)
    {
        s[i] = base[0];
        i++;
    }
    else
    {
        while (v > 0)
        {
            int d = v % B;
            s[i] = base[d];
            i++;
            v /= B;
        }
    }

    if (neg)
        s[0] = '-';

    reverse_span(s, neg, i - neg);
    s[i] = '\0';
    return s;
}
