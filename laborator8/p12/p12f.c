#include <stdio.h>
#include <stdlib.h>

#include "p12.h"

void citireVector(intVector vec, size_t nr_elem)
{
    for (int i = 0; i < nr_elem; i++)
    {
        scanf("%d", vec + i);
    }
}
void afisareVector(intVector vec, size_t nr_elem)
{
    for (int i = 0; i < nr_elem; i++)
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

// m - nr coloanei
int ConsumColoana(intMatrice mat, size_t n, size_t m) // bloc, n, 0
{
    int s = 0;
    for (int k = 0; k < n; k++)
    {
        s += mat[k][m];
    }
    return s;
}

// m = nr coloanei pe care facem calculul
// consumTotal = consumul de apa de pe toata coloanas
double redistribuire(intMatrice mat, size_t n, size_t m, int consumTotal, int pierderiColoana)
{
    // 3 4 <- consum apa            3.75 4
    // 5 6 <- consum apa            6.25 6
    // 10 10 <- apometre subsol
    // 2 0 <- pierderi
    // (3 / 8) * 2 + 3
    // (5 / 8) * 2 + 5
    double pierderi = ((double)mat[n][m] / consumTotal) * pierderiColoana + mat[n][m];
    return pierderi;
}