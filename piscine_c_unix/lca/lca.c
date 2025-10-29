#include "lca.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct nb
{
    int p;
    int q;
};

int isincluded(int *values, int length, int pq, int current)
{
    if (current >= length)
        return 0;
    if (values[current] == pq)
        return 1;
    return isincluded(values, length, pq, current * 2 + 1)
        + isincluded(values, length, pq, current * 2 + 2);
}

int lcaaux(int *values, int length, struct nb *nb, int cur)
{
    if (isincluded(values, length, nb->q, cur * 2 + 1)
        && isincluded(values, length, nb->p, cur * 2 + 1))
        return lcaaux(values, length, nb, cur * 2 + 1);
    else if (isincluded(values, length, nb->q, cur * 2 + 2)
             && isincluded(values, length, nb->p, cur * 2 + 2))
        return lcaaux(values, length, nb, cur * 2 + 2);
    else
        return values[cur];
}
int lca(int *values, int length, int p, int q)
{
    struct nb *nb = malloc(sizeof(struct nb));
    nb->p = p;
    nb->q = q;
    int res = lcaaux(values, length, nb, 0);
    free(nb);
    return res;
}
