#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    ssize_t k = write(STDOUT_FILENO, "Hello World!\n", 13);
    if (k == -1)
        return 1;
    return 0;
}
