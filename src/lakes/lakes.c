#include "lakes.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
static int W;
static int H;

static void explore(char **map, int x, int y)
{
    if (x < 0 || x >= W || y < 0 || y >= H)
        return;

    if (map[y][x] != '.')
        return;

    map[y][x] = '@';

    explore(map, x + 1, y);
    explore(map, x - 1, y);
    explore(map, x, y + 1);
    explore(map, x, y - 1);
}

int lakes(char **map, int width, int height)
{
    W = width;
    H = height;

    int count = 0;

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (map[y][x] == '.')
            {
                explore(map, x, y);
                count++;
            }
        }
    }

    return count;
}
