#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "p21.h"
#include "alocare.h"

int main(void)
{
    printf("Numarul de elemente al vectorului: ");
    int n;
    scanf("%d", &n);
    double *v = citireVectorReal(n);
    printf("Vectorul normelor este: ");
    double *norma = VectorNorma(v, n);
    afisareVectorReal(norma, 3);

    memset(v, 0, n);
    memset(norma, 0, 3);
    free(v);
    free(norma);
    v = nullptr;
    norma = nullptr;

    return EXIT_SUCCESS;
}