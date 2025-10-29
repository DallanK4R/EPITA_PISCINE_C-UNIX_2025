#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

#include "binary_cipher.h"

void my_xor_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    char *d = data;
    const char *k = key;
    size_t l = 0;
    for (size_t i = 0; i < data_len; i++)
    {
        if (l == key_len)
            l = 0;
        d[i] = d[i] ^ k[l];
        l++;
    }
}
