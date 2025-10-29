#include "simple_fnmatch.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
static int match(const char *p, const char *s);
static int star(const char *p, const char *s)
{
    while (*p == '*')
        p++;
    if (*p == '\0')
        return 0;
    for (;;)
    {
        if (match(p, s) == 0)
            return 0;
        if (*s == '\0')
            return 1;
        s++;
    }
}

static int eat_escaped(const char **pp, const char **ss)
{
    const char *p = *pp;
    const char *s = *ss;
    if (*p != '\\')
        return 2;
    p++;
    char pc = *p;
    if (pc == '\0')
        pc = '\\';
    if (*s == '\0' || *s != pc)
        return 1;
    p++;
    s++;
    *pp = p;
    *ss = s;
    return 0;
}

static int match(const char *p, const char *s)
{
    for (;;)
    {
        if (*p == '\0')
        {
            if (*s == '\0')
                return 0;
            return 1;
        }
        {
            int r = eat_escaped(&p, &s);
            if (r == 0)
                continue;
            if (r == 1)
                return 1;
        }
        if (*p == '?')
        {
            if (*s == '\0')
                return 1;
            p++;
            s++;
            continue;
        }
        if (*p == '*')
            return star(p, s);
        if (*s == '\0' || *p != *s)
            return 1;
        p++;
        s++;
    }
}

int simple_fnmatch(const char *pattern, const char *string)
{
    return match(pattern, string);
}
