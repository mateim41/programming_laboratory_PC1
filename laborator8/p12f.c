#include <stdio.h>
#include <stdlib.h>

#include "p12.h"

void citireVec(IntVector vec, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", vec + i);
    }
}
void afisareVec(IntVector vec, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(vec + i));
    }
    printf("\n");
}

void citireMat(IntMatrice mat, size_t n, size_t m)
{
    for (int i = 0; i < n; i++)
    {
        citireVec(mat[i], m);
    }
}
void afisareMat(IntMatrice mat, size_t n, size_t m)
{
    for (int i = 0; i < n; i++)
    {
        afisareVec(mat[i], m);
    }
}

int sumacol(IntMatrice mat, size_t n, size_t m) // m coloana pe care facem suma
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += mat[i][m];
    }
    return s;
}
int pierderi(IntVector vec, size_t i, int atot) // atot = apa totala din subsol
{
    return atot - vec[i]; // vec[i] = apa de la apartamentele de pe o coloana
}
double redistribuire(IntMatrice mat, size_t n, size_t m, int p, int scol)
{
    return (mat[n][m] + ((double)mat[n][m] / scol) * p);
}