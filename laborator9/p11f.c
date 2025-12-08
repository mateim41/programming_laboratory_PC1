#include <stdio.h>
#include <stdlib.h>

#include "p11.h"

void *xmalloc(const size_t size);
void **alocareMatrice(const size_t n, const size_t m, const size_t elemSize)
{
    void **matrix = xmalloc(n * sizeof(*matrix));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = xmalloc(m * elemSize);
    }
    return matrix;
}
void dealocareMatrice(void ***matrix, size_t n)
{
    if (matrix == NULL || *matrix == NULL)
    {
        return;
    }
    void **realMatrix = *matrix;
    for (int i = 0; i < n; i++)
    {
        free(realMatrix[i]);
    }
    free(realMatrix);
    *matrix = NULL;
}

int **citireMatrice(const size_t n, const size_t m)
{
    int **matrix = (int **)alocareMatrice(n, m, sizeof(int));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            scanf("%d", *(matrix + i) + j);
        }
    }
    return matrix;
}
void afisare_matrice(const int **matrix, const size_t n, const size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

// i, j <- ce linii vreau sa interschimb
void interschimbareLinii(int **matrix, const size_t i, const size_t j)
{
    int *aux = matrix[i];
    matrix[i] = matrix[j];
    matrix[j] = aux;
}
int *VectorMaxime_LinieMatrice(int **matrix, const size_t n, const size_t m)
{
    int *vectorMaxim = xmalloc(n * sizeof(*vectorMaxim));
    size_t k = 0;
    for (size_t i = 0; i < n; i++)
    {
        int max = 0;
        for (size_t j = 0; j < m; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
        vectorMaxim[k++] = max;
    }
    return vectorMaxim;
}
void ordonareMatrice(int **matrix, const size_t n, const size_t m)
{
    int *vMatrice_maxim = VectorMaxime_LinieMatrice(matrix, n, m); // 2 0 -3 1 2 4 10
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if (*(vMatrice_maxim + i) > *(vMatrice_maxim + j))
            {
                interschimbareLinii(matrix, i, j);
                int temp = *(vMatrice_maxim + i);
                *(vMatrice_maxim + i) = *(vMatrice_maxim + j);
                *(vMatrice_maxim + j) = temp;
            }
        }
    }
    free(vMatrice_maxim);
    vMatrice_maxim = NULL;
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
