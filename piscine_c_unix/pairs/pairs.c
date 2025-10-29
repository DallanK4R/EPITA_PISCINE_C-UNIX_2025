#include "pairs.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pair three_pairs_sum(const struct pair pair_1, const struct pair pair_2,
                            const struct pair pair_3)
{
    struct pair jaaj;
    jaaj.x = pair_1.x + pair_2.x + pair_3.x;
    jaaj.y = pair_1.y + pair_2.y + pair_3.y;
    return jaaj;
}

struct pair pairs_sum(const struct pair pairs[], size_t size)
{
    struct pair jiij;
    jiij.x = 0;
    jiij.y = 0;
    for (size_t i = 0; i < size; i++)
    {
        jiij.x += pairs[i].x;
        jiij.y += pairs[i].y;
    }
    return jiij;
}
