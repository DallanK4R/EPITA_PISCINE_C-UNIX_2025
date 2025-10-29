#include <assert.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    int fd = open(argv[1], O_RDWR);
    if (fd == -1)
        return 1;
    char buf[250000];
    size_t count = read(fd, buf, 250000);
    write(1, buf, count);
    close(fd);
    return 0;
}
