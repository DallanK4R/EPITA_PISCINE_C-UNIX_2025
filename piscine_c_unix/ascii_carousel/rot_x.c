#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

void rot_x(char *s, int x)
{
    if (!s)
        return;
    if (x < 0)
    {
        x %= 26;
        x += 26;
    }
    int i = 0;
    while (s[i])
    {
        if ((s[i] >= 'a' && s[i] <= 'z'))
            s[i] = ((s[i] - 'a' + x) % 26) + 'a';
        else if ((s[i] >= 'A' && s[i] <= 'Z'))
            s[i] = ((s[i] - 'A' + x) % 26) + 'A';
        i++;
    }
}
