#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n <= 2)
        return;
    char *tab = calloc(n, sizeof(char));
    if (!tab)
        return;
    tab[1] = 1;
    for (int i = 2; i * i < n; i++)
    {
        if (tab[i] == 0)
        {
            for (int k = i * i; k < n; k += i)
            {
                tab[k] = 1;
            }
        }
    }
    int cpt = 0;
    for (int j = 2; j < n; j++)
    {
        if (tab[j] == 0)
            cpt++;
    }
    free(tab);
    printf("%i\n", cpt);
}
