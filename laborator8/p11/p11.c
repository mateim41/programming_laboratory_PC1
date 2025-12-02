#include <stdio.h>
#include <stdlib.h>

#define NCOL 100
#define NROW 100
typedef int IntVector[NCOL];
typedef int IntMatrice[NROW][NCOL];

void citireVector(IntVector vec, size_t nr_elem);
void afisareVector(IntVector vec, size_t nr_elem);

void citireMatrice(IntMatrice mat, size_t n, size_t m);
void afisareMatrice(IntMatrice mat, size_t n, size_t m);

int main(void)
{
    size_t n, m; // n, m <= 10
    printf("Introduceti dimensiunile: ");
    scanf("%zd %zd", &n, &m);
    IntMatrice mat;
    citireMatrice(mat, n, m);
    afisareMatrice(mat, n, m);

    return EXIT_SUCCESS;
}

void citireVector(IntVector vec, size_t nr_elem)
{
    for (int i = 0; i < nr_elem; i++)
    {
        scanf("%d", vec + i);
    }
}

void afisareVector(IntVector vec, size_t nr_elem)
{
    for (int i = 0; i < nr_elem; i++)
    {
        printf("%d ", *(vec + i));
    }
    printf("\n");
}

void citireMatrice(IntMatrice mat, size_t n, size_t m)
{
    for (int i = 0; i < n; i++)
    {
        citireVector(mat[i], m);
    }
}

void afisareMatrice(IntMatrice mat, size_t n, size_t m)
{
    for (int i = 0; i < n; i++)
    {
        afisareVector(mat[i], m);
    }
}