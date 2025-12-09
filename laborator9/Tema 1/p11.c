#include <stdio.h>
#include <stdlib.h>

#include "p11.h"

int main(void)
{
    size_t n, m; // linii si coloane
    printf("Introduceti dimensiunile matricei: ");
    scanf("%zu %zu", &n, &m);

    printf("Introduceti matricea:\n");
    int **matrix = citireMatrice(n, m);
    printf("\n");

    ordonareMatrice(matrix, n, m);
    printf("Matricea ordonata:\n");
    afisareMatrice((const int **)matrix, n, m);
    printf("\n");

    dealocareMatrice((void ***)&matrix, n);
    return EXIT_SUCCESS;
}