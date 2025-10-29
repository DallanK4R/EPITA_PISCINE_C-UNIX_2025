#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int main(void)
{
    for (size_t i = 0; i < 26; i++)
    {
        putchar('a' + i);
        if (i == 25)
            putchar('\n');
        else
            putchar(' ');
    }
    return 0;
}
