#include <stdio.h>
#include <stdlib.h>

#include "alocare.h"

void *xmalloc(size_t size)
{
    void *v = malloc(size);
    if (v == nullptr)
    {
        fprintf(stderr, "Eroare alocare\n");
        exit(EXIT_FAILURE);
    }
    return v;
}

void *xcalloc(size_t nr_elem, size_t size)
{
    void *v = calloc(nr_elem, size);
    if (v == nullptr)
    {
        fprintf(stderr, "Eroare alocare\n");
        exit(EXIT_FAILURE);
    }
    return v;
}

void *xrealloc(void *v, size_t size)
{
    void *p = realloc(v, size);
    if (p == nullptr)
    {
        fprintf(stderr, "Eroare realocare\n");
        free(v);
        exit(EXIT_FAILURE);
    }
    v = p;
    return v;
}