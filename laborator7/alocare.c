#include <stdio.h>
#include <stdlib.h>

#include "alocare.h"
#include "culori.h"

void *xmalloc(size_t size)
{
    void *p = malloc(size);
    if (p == nullptr)
    {
        fprintf(stderr, "%sEroare alocare%s\n", RED, RESET);
        exit(EXIT_FAILURE);
    }
    return p;
}

void *xcalloc(size_t nr_elem, size_t size)
{
    void *v = calloc(nr_elem, size);
    if (v == nullptr)
    {
        fprintf(stderr, "%sEroare alocare%s\n", RED, RESET);
        exit(EXIT_FAILURE);
    }
    return v;
}

void *xrealloc(void *v, size_t size)
{
    void *p = realloc(v, size);
    if (p == nullptr)
    {
        fprintf(stderr, "%sEroare realocare%s\n", RED, RESET);
        free(v);
        exit(EXIT_FAILURE);
    }
    v = p;
    return v;
}