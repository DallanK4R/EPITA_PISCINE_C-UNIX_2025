
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void display_square(int width)
{
    if (width == 1)
    {
        putchar('*');
        putchar('\n');
        return;
    }

    if (width <= 0)
        return;
    if (width % 2 == 0)
        width += 1;
    for (int i = 0; i < width; i++)
    {
        putchar('*');
    }
    putchar('\n');
    for (int j = 0; j <= (width + 1) / 2 - 3; j++)
    {
        putchar('*');
        for (int o = 0; o < width - 2; o++)
        {
            putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }
    for (int h = 0; h < width; h++)
    {
        putchar('*');
    }
    putchar('\n');
}
