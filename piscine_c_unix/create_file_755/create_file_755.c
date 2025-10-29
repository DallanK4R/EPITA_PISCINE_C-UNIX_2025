#include <assert.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>

int create_file_755(const char *path)
{
    int k = open(path, O_CREAT, 0755);
    if (k == -1)
        return 1;
    return 0;
}
