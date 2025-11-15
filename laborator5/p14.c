#include <stdio.h>
#include <stdlib.h>
#include "vectorint.h"

int main(void)
{
    int n;
    printf("Numarul de elemente al sirului: ");
    scanf("%d", &n);
    int v[100];
    printf("Elementele vectorului sunt: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    int u[100];                // vectorul cu elemente distincte
    int c = distinct(v, u, n); // numarul de elemente din noul vector
    printf("Elementele noului vector sunt: ");
    for (int i = 0; i < c; i++)
    {
        printf("%d ", u[i]);
        if (i == c - 1)
            printf("\n");
    }

    return EXIT_SUCCESS;
}