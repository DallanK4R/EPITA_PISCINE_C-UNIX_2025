
#define _POSIX_C_SOURCE 200809L

#include "commands.h"

#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int help(const char *arg)
{
    if (arg)
    {
        warnx("jaaj");
        return -1;
    }
    printf("The available commands are:\n");
    printf("help\n");
    printf("hello\n");
    printf("print string\n");
    printf("exit\n");
    printf("cat file\n");
    return 0;
}

int hello(const char *arg)
{
    if (arg)
    {
        warnx("jaaj");
        return -1;
    }
    printf("hello\n");
    return 0;
}

int print(const char *arg)
{
    if (!arg)
    {
        warnx("jaaj");
        return -1;
    }
    printf("%s\n", arg);
    return 0;
}

int myexit(const char *arg)
{
    if (arg)
    {
        warnx("jaaj");
        return -1;
    }
    exit(0);
}

int cat(const char *arg)
{
    if (!arg)
    {
        warnx("jaaj");
        return -1;
    }
    int fdt = open(arg, O_DIRECTORY);
    if (fdt >= 0)
    {
        warnx("jaaj");
        return -1;
    }
    close(fdt);
    int fd = open(arg, O_RDONLY);
    if (fd < 0)
    {
        warnx("jaaj");
        return -1;
    }
    char buf[260000];
    size_t count = read(fd, buf, 260000);
    write(1, buf, count);
    close(fd);
    return 0;
}
