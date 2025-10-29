#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

unsigned char rol(unsigned char value, unsigned char roll)
{
    unsigned char vt;
    for (unsigned char i = 0; i < roll; i++)
    {
        vt = value;
        value = value << 1;
        if (value != vt * 2)
            value++;
    }
    return value;
}
