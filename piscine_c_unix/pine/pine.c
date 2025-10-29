
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int pine(unsigned n)
{
    if (n < 3)
        return 1;
    int w = 1;
    int s = n - 1;
    int yu = n;
    for (int i = 0; i < yu; i++)
    {
        for (int j = 0; j < s; j++)
        {
            putchar(' ');
        }
        for (int o = 0; o < w; o++)
        {
            putchar('*');
        }
        putchar('\n');
        s -= 1;
        w += 2;
    }
    for (int k = 0; k < yu / 2; k++)
    {
        for (int y = 0; y < yu - 1; y++)
        {
            putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }
    return 0;
}
