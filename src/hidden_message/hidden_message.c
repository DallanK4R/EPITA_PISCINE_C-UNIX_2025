#define _POSIX_C_SOURCE 200809L
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    FILE *f = fopen(argv[1], "r");
    if (!f)
        return 1;
    size_t k = 32;
    char *buffer = calloc(33, sizeof(char));
    int res = getdelim(&buffer, &k, ';', f);
    while (res != -1)
    {
        putchar(buffer[3]);
        res = getdelim(&buffer, &k, ';', f);
    }
    putchar('\n');
    free(buffer);
    return 0;
}
