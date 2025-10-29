#include <assert.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

static void read1(int fd)
{
    char buf[1];
    int res = 1;
    while (res)
    {
        res = read(fd, buf, 1);
        if (res == -1)
            err(1, "err read");
        if (res && write(STDOUT_FILENO, buf, res) == -1)
            err(1, "err writing");
        if (res && lseek(fd, 1, SEEK_CUR) == -1)
            err(1, "err see");
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        err(1, "eerrr op");
    read1(fd);
    close(fd);
    return 0;
}
