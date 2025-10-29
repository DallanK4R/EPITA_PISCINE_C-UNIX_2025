#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

static size_t partition(int *tab, size_t lo, size_t hi)
{
    int pivot = tab[hi];
    size_t i = lo;
    for (size_t j = lo; j + 1 <= hi; j++)
    {
        if (tab[j] <= pivot)
        {
            int t = tab[i];
            tab[i] = tab[j];
            tab[j] = t;
            i++;
        }
    }
    int t = tab[i];
    tab[i] = tab[hi];
    tab[hi] = t;
    return i;
}

static void qaux(int *tab, size_t lo, size_t hi)
{
    if (lo >= hi)
        return;
    size_t p = partition(tab, lo, hi);
    if (p > 0)
        qaux(tab, lo, p - 1);
    qaux(tab, p + 1, hi);
}

void quicksort(int *tab, size_t len)
{
    if (!tab || len == 0)
        return;
    qaux(tab, 0, len - 1);
}
