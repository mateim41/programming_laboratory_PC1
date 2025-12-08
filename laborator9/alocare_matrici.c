#include <stdio.h>
#include <stdlib.h>

#include "alocare_matrici.h"

void *xmalloc(const size_t size);
void **alocare_matrice(const size_t n, const size_t m, const size_t elemSize)
{
    void **matrix = xmalloc(n * sizeof(*matrix));
    void *rowStart = xmalloc(n * m * elemSize);
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = (void *)((char *)rowStart + (i * m * elemSize));
    }
    return matrix;
}

void dealocare_matrice(void ***matrix)
{
    if (matrix == NULL || *matrix == NULL)
    {
        return;
    }
    void **realMatrix = *matrix;
    free(realMatrix[0]);
    free(realMatrix);
    *matrix = NULL;
}

void *xmalloc(const size_t size)
{
    void *v = malloc(size);
    if (v == NULL)
    {
        fprintf(stderr, "Eroare alocare\n");
        exit(EXIT_FAILURE);
    }
    return v;
}