#include "hash_map.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_map *hash_map_init(size_t size)
{
    if (!size)
        return NULL;
    struct hash_map *m = malloc(sizeof(*m));
    if (!m)
        return NULL;
    m->data = calloc(size, sizeof(*m->data));
    if (!m->data)
    {
        free(m);
        return NULL;
    }
    m->size = size;
    return m;
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (!hash_map || !hash_map->data || !key || !hash_map->size)
        return false;
    size_t idx = hash(key) % hash_map->size;
    struct pair_list *p = hash_map->data[idx];
    while (p)
    {
        if (strcmp(p->key, key) == 0)
        {
            p->value = value;
            if (updated)
                *updated = true;
            return true;
        }
        p = p->next;
    }
    struct pair_list *n = malloc(sizeof(*n));
    if (!n)
        return false;
    n->key = key;
    n->value = value;
    n->next = hash_map->data[idx];
    hash_map->data[idx] = n;
    if (updated)
        *updated = false;
    return true;
}

void hash_map_free(struct hash_map *hash_map)
{
    if (!hash_map)
        return;
    if (hash_map->data)
    {
        for (size_t i = 0; i < hash_map->size; i++)
        {
            struct pair_list *p = hash_map->data[i];
            while (p)
            {
                struct pair_list *q = p->next;
                free(p);
                p = q;
            }
        }
        free(hash_map->data);
    }
    free(hash_map);
}

void hash_map_dump(struct hash_map *hash_map)
{
    if (!hash_map || !hash_map->data)
        return;
    for (size_t i = 0; i < hash_map->size; i++)
    {
        struct pair_list *p = hash_map->data[i];
        if (!p)
            continue;
        int first = 1;
        while (p)
        {
            if (!first)
                printf(", ");
            printf("%s: %s", p->key, p->value);
            first = 0;
            p = p->next;
        }
        putchar('\n');
    }
}

const char *hash_map_get(const struct hash_map *hash_map, const char *key)
{
    if (!hash_map || !hash_map->data || !key || !hash_map->size)
        return NULL;
    size_t idx = hash(key) % hash_map->size;
    struct pair_list *p = hash_map->data[idx];
    while (p)
    {
        if (strcmp(p->key, key) == 0)
            return p->value;
        p = p->next;
    }
    return NULL;
}

bool hash_map_remove(struct hash_map *hash_map, const char *key)
{
    if (!hash_map || !hash_map->data || !key || !hash_map->size)
        return false;
    size_t idx = hash(key) % hash_map->size;
    struct pair_list *p = hash_map->data[idx];
    struct pair_list *prev = NULL;
    while (p)
    {
        if (strcmp(p->key, key) == 0)
        {
            if (prev)
                prev->next = p->next;
            else
                hash_map->data[idx] = p->next;
            free(p);
            return true;
        }
        prev = p;
        p = p->next;
    }
    return false;
}
