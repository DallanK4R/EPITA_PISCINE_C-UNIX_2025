#include "null_terminated_arrays.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void reverse_matrix(const char ***matrix)
{
    int i1 = 0;
    while (matrix[i1] != NULL)
    {
        int cpt = 0;
        while (matrix[i1][cpt] != NULL)
        {
            cpt++;
        }
        for (int i = 0; i < cpt / 2; i++)
        {
            const char *temp = matrix[i1][i];
            matrix[i1][i] = matrix[i1][cpt - i - 1];
            matrix[i1][cpt - i - 1] = temp;
        }
        i1++;
    }
    int cptreal = 0;
    while (matrix[cptreal] != NULL)
    {
        cptreal++;
    }
    for (int i = 0; i < cptreal / 2; i++)
    {
        const char **temp = matrix[i];
        matrix[i] = matrix[cptreal - i - 1];
        matrix[cptreal - i - 1] = temp;
    }
    cptreal++;
}
