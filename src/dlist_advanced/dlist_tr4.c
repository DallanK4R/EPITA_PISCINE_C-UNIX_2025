#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

static int *dlist_to_array(const struct dlist *list, size_t n)
{
    if (!list || n == 0)
        return NULL;
    int *a = malloc(n * sizeof(int));
    if (!a)
        return NULL;
    struct dlist_item *it = list->head;
    for (size_t i = 0; i < n; i++)
    {
        a[i] = it->data;
        it = it->next;
    }
    return a;
}

static size_t min3(size_t a, size_t b, size_t c)
{
    size_t t = a < b ? a : b;
    return t < c ? t : c;
}

static size_t levenshtein_arrays(const int *a, size_t n, const int *b, size_t m)
{
    size_t *prev = malloc((m + 1) * sizeof(size_t));
    size_t *cur = malloc((m + 1) * sizeof(size_t));
    if (!prev || !cur)
    {
        free(prev);
        free(cur);
        return 0;
    }
    for (size_t j = 0; j <= m; j++)
        prev[j] = j;
    for (size_t i = 1; i <= n; i++)
    {
        cur[0] = i;
        for (size_t j = 1; j <= m; j++)
        {
            size_t cost = (a ? a[i - 1] : 0) == (b ? b[j - 1] : 0) ? 0 : 1;
            size_t del = prev[j] + 1;
            size_t ins = cur[j - 1] + 1;
            size_t sub = prev[j - 1] + cost;
            cur[j] = min3(del, ins, sub);
        }
        size_t *tmp = prev;
        prev = cur;
        cur = tmp;
    }
    size_t ans = prev[m];
    free(prev);
    free(cur);
    return ans;
}

unsigned int dlist_levenshtein(const struct dlist *list1,
                               const struct dlist *list2)
{
    size_t n = list1 ? list1->size : 0;
    size_t m = list2 ? list2->size : 0;
    int *a = dlist_to_array(list1, n);
    int *b = dlist_to_array(list2, m);
    size_t d = levenshtein_arrays(a, n, b, m);
    free(a);
    free(b);
    return d;
}
