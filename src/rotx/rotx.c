#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 0;
    int k = atoi(argv[1]);
    char s[1];
    size_t count = read(0, s, 1);
    while (count)
    {
        int x = k;
        if ((s[0] >= 'a' && s[0] <= 'z'))
        {
            if (x < 0)
            {
                x %= 26;
                x += 26;
            }
            s[0] = ((s[0] - 'a' + x) % 26) + 'a';
        }
        else if ((s[0] >= 'A' && s[0] <= 'Z'))
        {
            if (x < 0)
            {
                x %= 26;
                x += 26;
            }
            s[0] = ((s[0] - 'A' + x) % 26) + 'A';
        }
        else if ((s[0] >= '0' && s[0] <= '9'))
        {
            if (x < 0)
            {
                x %= 10;
                x += 10;
            }
            s[0] = ((s[0] - '0' + x) % 10) + '0';
        }
        write(1, s, 1);
        count = read(0, s, 1);
    }
    return 0;
}
