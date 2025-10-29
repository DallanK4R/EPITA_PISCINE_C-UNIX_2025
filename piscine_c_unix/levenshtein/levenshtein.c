
#include "levenshtein.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static size_t slen(const char *s)
{
    size_t n = 0;
    while (s[n] != '\0')
        n++;
    return n;
}

static size_t min3(size_t a, size_t b, size_t c)
{
    size_t m = a < b ? a : b;
    return m < c ? m : c;
}

size_t levenshtein(const char *s1, const char *s2)
{
    size_t n1 = slen(s1);
    size_t n2 = slen(s2);

    size_t *row0 = malloc((n2 + 1) * sizeof(*row0));
    size_t *row1 = malloc((n2 + 1) * sizeof(*row1));

    for (size_t j = 0; j <= n2; ++j)
        row0[j] = j;

    for (size_t i = 1; i <= n1; ++i)
    {
        row1[0] = i;
        for (size_t j = 1; j <= n2; ++j)
        {
            size_t cost = (s1[i - 1] != s2[j - 1]);
            size_t del = row0[j] + 1;
            size_t ins = row1[j - 1] + 1;
            size_t sub = row0[j - 1] + cost;
            row1[j] = min3(del, ins, sub);
        }
        size_t *tmp = row0;
        row0 = row1;
        row1 = tmp;
    }

    size_t d = row0[n2];
    free(row0);
    free(row1);
    return d;
}
