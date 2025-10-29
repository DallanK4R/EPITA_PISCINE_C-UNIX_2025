#include "complex.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void print_complex(struct complex a)
{
    if (a.img < 0)
        printf("complex(%.2f - %.2fi)\n", a.real, -a.img);
    else
        printf("complex(%.2f + %.2fi)\n", a.real, a.img);
}

struct complex neg_complex(struct complex a)
{
    a.real *= -1;
    a.img *= -1;
    return a;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex n;
    n.real = a.real + b.real;
    n.img = a.img + b.img;
    return n;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    struct complex n;
    n.real = a.real - b.real;
    n.img = a.img - b.img;
    return n;
}
struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex n;
    n.real = a.real * b.real - a.img * b.img;
    n.img = a.real * b.img + b.real * a.img;
    return n;
}

struct complex div_complex(struct complex a, struct complex b)
{
    struct complex n;
    n.real =
        (a.real * b.real + a.img * b.img) / (b.real * b.real + b.img * b.img);
    n.img =
        (a.img * b.real - a.real * b.img) / (b.real * b.real + b.img * b.img);
    return n;
}
