#include <stdio.h>
#include <stdlib.h>

#include "alocare.h"

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