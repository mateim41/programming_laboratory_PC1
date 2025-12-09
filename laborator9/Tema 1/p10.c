#include <stdio.h>
#include <stdlib.h>

#include "p10.h"
#include "alocare_matrici.h"

int main(void)
{
    size_t n, m;
    printf("Dimensiunea matricei: ");
    scanf("%zu %zu", &n, &m);

    printf("Introduceti matricea:\n");
    const int **matrice = (const int **)citireMatrice(n, m);
    printf("\n");
    afisareMatrice(matrice, n, m);

    dealocareMatrice((void ***)&matrice, n);
    return EXIT_SUCCESS;
}