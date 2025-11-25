#include <stdio.h>
#include <stdlib.h>

#define NROW 10
#define NCOL 10

typedef int IntVector[NCOL];
typedef int IntMatrix[NROW][NCOL];

void afisareVec(IntVector vec, size_t n);
void citireVec(IntVector vec, size_t n);

void citireMat(IntMatrix mat, size_t n, size_t m);
void afisareMat(IntMatrix, size_t n, size_t m);

int main(void)
{
    /*
    IntMatrix mat = {
        {1, 2, 3}, // prima linie
        {4, 5, 6}  // a doua linie
    };
    */

    return EXIT_SUCCESS;
}

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
        printf("%d ", vec[i]);
    }
    printf("\n");
}

void citireMat(IntMatrix mat, size_t n, size_t m)
{
    for (int i = 0; i < n; i++)
    {
        citireVec(mat[i], m);
    }
}

void afisareMat(IntMatrix mat, size_t n, size_t m)
{
    for (int i = 0; i < n; i++)
    {
        afisareVec(mat[i], m);
    }
}