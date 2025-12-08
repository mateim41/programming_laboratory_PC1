#include <stdio.h>
#include <stdlib.h>

#include "alocare_matrici.h"
#include "p10.h"

int **citireMatriceDinamic(const size_t n, const size_t m)
{
    int **matrix = (int **)alocare_matrice(n, m, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", *(matrix + i) + j);
        }
    }
    return matrix;
}

void afisareMatrice(const int **matrix, const size_t n, const size_t m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}