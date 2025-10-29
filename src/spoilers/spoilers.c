#include <assert.h>
#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        write(2, "Invalid number of arguments\n", 28);
        return 1;
    }
    int k = open(argv[1], O_RDONLY);
    if (k == -1)
    {
        write(2, "Could not open file\n", 20);
        return 1;
    }
    char buffer[1];
    char res[3];
    res[2] = '\n';
    int index = 0;
    int i = -1;
    while (index < 2)
    {
        lseek(k, i, SEEK_END);
        ssize_t j = read(k, buffer, 1);
        if (j == -1)
        {
            err(1, "JAAJ");
            return 1;
        }
        if (j != 1)
        {
            write(2, "File is not long enough\n", 24);
            return 1;
        }
        if (!isspace(buffer[0]))
        {
            res[index] = buffer[0];
            index++;
        }
        i -= 1;
    }
    write(STDOUT_FILENO, res + 1, 1);
    write(STDOUT_FILENO, res, 1);
    write(STDOUT_FILENO, res + 2, 1);
    return 0;
}
