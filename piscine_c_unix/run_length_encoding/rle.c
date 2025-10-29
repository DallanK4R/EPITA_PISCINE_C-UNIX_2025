#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *readd(char *res, int nb, int cpt)
{
    res = realloc(res, sizeof(char) * 1 + sizeof(char) * 2 * nb);
    res[2 * (nb - 1)] = cpt + '0';
    return res;
}

char *rle_encode(const char *s)
{
    if (s[0] == 0)
        return NULL;
    int i = 0;
    int cpt = 1;
    char *res = malloc(sizeof(char));
    int nb = 1;
    if (!res)
        return NULL;
    char current = s[0];
    while (s[i + 1])
    {
        if (cpt == 9)
        {
            res = readd(res, nb, cpt);
            res[2 * (nb - 1) + 1] = s[i];
            nb++;
            cpt = 0;
        }
        if (current != s[i + 1])
        {
            if (cpt != 0)
            {
                res = readd(res, nb, cpt);
                res[2 * (nb - 1) + 1] = s[i];
                nb++;
            }
            cpt = 1;
            current = s[i + 1];
        }
        else
            cpt++;
        i++;
    }
    res = readd(res, nb, cpt);
    res[2 * (nb - 1) + 1] = s[i];
    res[2 * (nb - 1) + 2] = 0;
    return res;
}

int finalength(const char *s)
{
    int cpt = 0;
    int i = 0;
    while (s[i])
    {
        cpt += s[i] - '0';
        i += 2;
    }
    return cpt;
}

char *rle_decode(const char *s)
{
    if (!*s)
        return "";
    if (*s == 0)
        return "";
    int flen = finalength(s);
    char *res = calloc(flen + 1, sizeof(char));
    if (!res)
        return NULL;
    int i = 0;
    int j = 0;
    while (s[i])
    {
        int k = s[i] - '0';
        while (k > 0)
        {
            res[j++] = s[i + 1];
            k--;
        }
        i += 2;
    }
    return res;
}
