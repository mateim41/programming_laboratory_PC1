#include <stdio.h>
#include <stdlib.h>

#include "p11.h"

void *xmalloc(const size_t size);
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
    void **mainMatrix = *matrix;
    for (size_t i = 0; i < nrlinii; i++)
    {
        free(mainMatrix[i]);
    }
    free(mainMatrix);
    *matrix = NULL;
}

int **citireMatrice(const size_t nrlinii, const size_t nrcoloane)
{
    int **matrix = (int **)alocareMatrice(nrlinii, nrcoloane, sizeof(int));
    for (size_t i = 0; i < nrlinii; i++)
    {
        for (size_t j = 0; j < nrcoloane; j++)
        {
            scanf("%d", *(matrix + i) + j);
        }
    }
    return matrix;
}
void afisareMatrice(const int **matrix, const size_t nrlinii, const size_t nrcoloane)
{
    for (size_t i = 0; i < nrlinii; i++)
    {
        for (size_t j = 0; j < nrcoloane; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int *vectorMaxime(const int **matrix, const size_t nrlinii, const size_t nrcoloane);
// i, j <- liniile pe care vreau sa le schimb
void interschimbareLinii(int **matrix, const size_t i, const size_t j);
void ordonareMatrice(int **matrix, const size_t nrlinii, const size_t nrcoloane)
{
    int *maximLinieMatrice = vectorMaxime((const int **)matrix, nrlinii, nrcoloane);
    for (size_t i = 0; i < nrlinii - 1; i++)
    {
        for (size_t j = i + 1; j < nrlinii; j++)
        {
            if (maximLinieMatrice[i] > maximLinieMatrice[j])
            {
                interschimbareLinii(matrix, i, j);
                int temp = *(maximLinieMatrice + i);
                *(maximLinieMatrice + i) = *(maximLinieMatrice + j);
                *(maximLinieMatrice + j) = temp;
            }
        }
    }
    free(maximLinieMatrice);
    maximLinieMatrice = NULL;
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
int *vectorMaxime(const int **matrix, const size_t nrlinii, const size_t nrcoloane)
{
    int *maximLinieMatrice = xmalloc(nrlinii * sizeof(*maximLinieMatrice));
    for (size_t i = 0; i < nrlinii; i++)
    {
        int max = 0;
        for (size_t j = 0; j < nrcoloane; j++)
        {
            if (*(*(matrix + i) + j) > max)
            {
                max = *(*(matrix + i) + j);
            }
        }
        *(maximLinieMatrice + i) = max;
    }
    return maximLinieMatrice;
}
void interschimbareLinii(int **matrix, const size_t i, const size_t j)
{
    int *aux = matrix[i];
    matrix[i] = matrix[j];
    matrix[j] = aux;
}