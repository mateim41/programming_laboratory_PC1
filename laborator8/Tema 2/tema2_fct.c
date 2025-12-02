#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tema2.h"

void citireVector(intVector vec, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", vec + i);
    }
}
void afisareVector(intVector vec, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(vec + i));
    }
    printf("\n");
}
void citireMatrice(intMatrice mat, size_t n, size_t m)
{
    for (int i = 0; i < n; i++)
    {
        citireVector(mat[i], m);
    }
}
void afisareMatrice(intMatrice mat, size_t n, size_t m)
{
    for (int i = 0; i < n; i++)
    {
        afisareVector(mat[i], m);
    }
}

void sumaMatrici(intMatrice S, intMatrice A, size_t n, size_t m, intMatrice B, size_t p, size_t q)
{
    // Anm Bpq 22 23
    if (n != p || m != q)
    {
        fprintf(stderr, "Dimensiunea matricilor este gresita\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                S[i][j] = A[i][j] + B[i][j];
            }
        }
    }
}
void produsMatrici(intMatrice P, intMatrice A, size_t n, size_t m, intMatrice B, size_t p, size_t q)
{
    /*
        1 2 3       1 2 3       6  28 42
        4 5 6       1 4 6       15 64 96
                    1 6 9
        mn pq
    */
    if (m != p)
    {
        fprintf(stderr, "Dimensiune incorecta a matricilor\n");
        exit(EXIT_FAILURE);
    }
    // a[0][0] * b[0][0] + a[0][1] * b[1][0] +a[0][2] * b[0][2]
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        k = 0;
        while (k < q) // 0 < 3
        {
            for (int j = 0; j < m; j++)
            {
                P[i][k] += A[i][j] * B[j][k];
            }
            k++;
        }
    }
}
// cazul general
void transpusaMatrice(intMatrice T, intMatrice A, size_t n, size_t m)
{
    /*
        1 2 3   1 4 7
        4 5 6   2 5 8
        7 8 9   3 6 9
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            T[j][i] = A[i][j];
        }
    }
}

// Alocare dinamica p23

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
void **alocareMatrice(size_t n, size_t m, size_t elemSize)
{
    void **matrix = xmalloc(n * sizeof(*matrix));
    void *rowStart = xmalloc(n * m * elemSize);
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = (void *)((char *)rowStart + (i * m * elemSize));
    }
    return matrix;
}
int **citireMatrice_dinamic(size_t n, size_t m)
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
void afisareMatrice_dinamic(int **matrix, size_t n, size_t m)
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
void dealocareMatrice(void ***matrix)
{
    if (matrix == nullptr || *matrix == nullptr)
    {
        return;
    }
    void **mainMatrix = *matrix;
    free(mainMatrix[0]);
    free(mainMatrix);
    *matrix = nullptr;
}
int **matrice_unitate(size_t n, size_t m)
{
    int **matrix = (int **)alocareMatrice(n, m, sizeof(int));
    memset(matrix[0], 0, n * m * sizeof(int));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (i == j)
            {
                *(*(matrix + i) + j) = 1;
            }
        }
    }
    return matrix;
}
int **produsMatrice_dinamic(int **A, size_t n, size_t m, int **B, size_t p, size_t q)
{
    /*
        1 2 3       1 1 1       6  8  8
        1 4 5       1 2 2       10 14 14
        1 6 7       1 1 1       14 20 20

        3 3     1 1 1 1
        3 3     1 1 1 1
        3 3
    */
    if (m != p)
    {
        fprintf(stderr, "Eroare calcul\n");
        return NULL;
    }
    int **P = (int **)alocareMatrice(n, q, sizeof(int));
    memset(P[0], 0, n * q * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < q; k++)
        {
            for (int j = 0; j < m; j++)
            {
                P[i][k] += A[i][j] * B[j][k];
            }
        }
    }
    return P;
}
void transpusaMatrice_dinamic(int **T, int **A, size_t n, size_t m)
{
    /*
        1 2 3   1 4 7
        4 5 6   2 5 8
        7 8 9   3 6 9
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            T[i][j] = A[j][i];
        }
    }
}