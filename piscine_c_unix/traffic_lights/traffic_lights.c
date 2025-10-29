#include "traffic_lights.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void init(unsigned char *lights)
{
    *lights &= *lights ^ *lights;
}

void turn_on(unsigned char *lights, unsigned char light_num)
{
    if (!lights)
        return;
    *lights |= (1u << (light_num - 1u));
}

void turn_off(unsigned char *lights, unsigned char light_num)
{
    if (!lights)
        return;
    *lights &= ~(1u << (light_num - 1u));
}

void next_step(unsigned char *lights)
{
    if (!lights)
        return;
    unsigned char v = *lights & 0x0Fu;
    v = ((v << 1) | (v >> 3)) & 0x0Fu;
    *lights = (*lights & 0xF0u) | v;
}

void reverse(unsigned char *lights)
{
    if (!lights)
        return;
    *lights ^= 0x0Fu;
}

void swap(unsigned char *lights_1, unsigned char *lights_2)
{
    if (!lights_1 || !lights_2)
        return;
    unsigned char t = *lights_1;
    *lights_1 = *lights_2;
    *lights_2 = t;
}
