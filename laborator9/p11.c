#include <stdio.h>
#include <stdlib.h>

#include "p11.h"

int main(void)
{
    size_t n, m;
    printf("Introduceti dimensiunile matricei: ");
    scanf("%zd %zd", &n, &m);

    printf("Cititi matricea:\n");
    int **matrix = citireMatrice(n, m);
    printf("\n");

    ordonareMatrice(matrix, n, m);
    printf("Matricea ordonata este:\n");
    afisare_matrice((const int **)matrix, n, m);

    dealocareMatrice((void ***)&matrix, n);
    return EXIT_SUCCESS;
}