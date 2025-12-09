#include <stdio.h>
#include <stdlib.h>

#include "alocare_matrici.h"

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
void **alocareMatrice(const size_t nrlinii, const size_t nrcoloane, const size_t elemSize)
{
    void **matrix = xmalloc(nrlinii * sizeof(*matrix));
    for (size_t i = 0; i < nrlinii; i++)
    {
        matrix[i] = xmalloc(nrcoloane * sizeof(elemSize));
    }
    return matrix;
}
void dealocareMatrice(void ***matrix, const size_t nrlinii)
{
    if (matrix == NULL || *matrix == NULL)
    {
        return;
    }
    void **realMatrix = *matrix;
    for (size_t i = 0; i < nrlinii; i++)
    {
        free(realMatrix[i]);
    }
    free(realMatrix);
    *matrix = NULL;
}