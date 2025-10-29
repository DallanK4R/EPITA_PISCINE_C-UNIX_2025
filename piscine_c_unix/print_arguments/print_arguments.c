#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 0)
        return 0;
    for (int i = 1; i < argc; i++)
        puts(argv[i]);
    return 0;
}
