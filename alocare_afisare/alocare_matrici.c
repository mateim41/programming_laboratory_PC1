#include <stdio.h>
#include <stdlib.h>

#include "alocare_matrici.h"

void *xmalloc(size_t size)
{
    void *v = malloc(size);
    if (v == NULL)
    {
        fprintf(stderr, "Eroare alocare\n");
        exit(EXIT_FAILURE);
    }
    return v;
}

void **alocareMatrice_fragmented(size_t n, size_t m, size_t elemSize)
{
    void **matrix = xmalloc(n * sizeof(*matrix));
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = xmalloc(m * elemSize);
    }
    return matrix;
}
void **alocareMatrice_contiguous(size_t n, size_t m, size_t elemSize)
{
    void **matrix = xmalloc(n * sizeof(*matrix));
    void *row = xmalloc(n * m * elemSize);
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = (void *)((char *)row + (i * m * elemSize));
    }
    return matrix;
}

void dealocareMatrice_fragmented_mod1(void ***matrix, size_t n)
{
    if (matrix == NULL || *matrix == NULL)
    {
        return;
    }
    void **mainMatrix = *matrix;
    for (size_t i = 0; i < n; i++)
    {
        free(mainMatrix[i]);
    }
    free(mainMatrix);
    *matrix = NULL;
}
void dealocareMatrice_fragmented_mod2(void **matrix, size_t n)
{
    if (matrix == NULL)
    {
        return;
    }
    for (size_t i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    // trb facut matrix = NULL in main
}

void dealocareMatrice_contiguous_mod1(void ***matrix)
{
    if (matrix == NULL || *matrix == NULL)
    {
        return;
    }
    void **mainMatrix = *matrix;
    free(mainMatrix[0]);
    free(mainMatrix);
    *matrix = NULL;
}
void dealocareMatrice_contiguous_mod2(void **matrix)
{
    if (matrix == NULL)
    {
        return;
    }
    free(matrix[0]);
    free(matrix);
    // trb matrix = NULL in main
}

int **citireMatrice(size_t n, size_t m)
{
    int **matrix = (int **)alocareMatrice_contiguous(n, m, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", *(matrix + i) + j);
        }
    }
    return matrix;
}
void afisareMatrice_int(int **matrix, size_t n, size_t m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}