#include "is_set.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

unsigned int is_set(unsigned int value, unsigned char n)
{
    return (value >> (n - 1)) % 2;
}
