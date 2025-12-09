#include <stdio.h>
#include <stdlib.h>

#include "alocare_matrici.h"
#include "p12_3.h"

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

// i, j <- liniile pe care le interschimb
void interschimbareLinii(int **matrix, const size_t i, const size_t j)
{
    int *aux = *(matrix + i);
    *(matrix + i) = *(matrix + j);
    *(matrix + j) = aux;
}

// u, v = coloanele care se interschimba
void interschimbareColoane(int **matrix, const size_t nrlinii, const size_t u, const size_t v)
{
    for (int i = 0; i < nrlinii; i++)
    {
        int aux = matrix[i][u];
        matrix[i][u] = matrix[i][v];
        matrix[i][v] = aux;
    }
}

/*
    2 5 6
    1 1 0
    3 1 -3
*/

// interschimb coloanele
void primaLinieCresc(int **matrix, const size_t nrlinii, const size_t nrcoloane)
{
    for (int i = 0; i < nrcoloane - 1; i++)
    {
        for (int j = i + 1; j < nrcoloane; j++)
        {
            if (*(*(matrix) + i) > *(*(matrix) + j))
            {
                interschimbareColoane(matrix, nrlinii, i, j);
            }
        }
    }
}

// interschimb liniile
void primaColoanaCresc(int **matrix, const size_t nrlinii, const size_t nrcoloane)
{
    for (int i = 0; i < nrlinii - 1; i++)
    {
        for (int j = i + 1; j < nrlinii; j++)
        {
            if (*(*(matrix + i)) > *(*(matrix + j)))
            {
                interschimbareLinii(matrix, i, j);
            }
        }
    }
}

// interschimb linii si coloane
void diagPrincCresc(int **matrix, const size_t nrlinii, const size_t nrcoloane)
{
    for (int i = 0; i < nrlinii; i++)
    {
        for (int j = i + 1; j < nrcoloane; j++)
        {
            if (matrix[i][i] > matrix[j][j])
            {
                interschimbareColoane(matrix, nrlinii, i, j);
                interschimbareLinii(matrix, i, j);
            }
        }
    }
}

// interschimb linii si coloane
void diagSecCresc(int **matrix, const size_t nrlinii, const size_t nrcoloane)
{
    for (int i = 0; i < nrlinii; i++)
    {
        for (int j = i + 1; j < nrlinii; j++)
        {
            if (matrix[i][nrlinii - 1 - i] > matrix[j][nrlinii - 1 - j])
            {
                interschimbareColoane(matrix, nrlinii, nrlinii - 1 - i, nrlinii - 1 - j);
                interschimbareLinii(matrix, i, j);
            }
        }
    }
}

// interschimb linii
void LiniaMedianaVerticala(int **matrix, const size_t nrlinii, const size_t nrcoloane)
{
    const size_t lin_mediana = (nrcoloane - 1) / 2;
    for (int i = 0; i < nrlinii - 1; i++)
    {
        for (int j = i + 1; j < nrlinii; j++)
        {
            if (*(*(matrix + i) + lin_mediana) > *(*(matrix + j) + lin_mediana))
            {
                interschimbareLinii(matrix, i, j);
            }
        }
    }
}