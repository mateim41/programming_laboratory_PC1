#include <stdlib.h>
#include <stdio.h>
#include "vectorint.h"

int main(void)
{
    int n; // nr de meri maxim
    printf("Introduceti numarul de pomi: ");
    scanf("%d", &n);
    int v[50];
    printf("Citim numarul de mere pentru fiecare copac: ");
    citire(v, n);
    double m = 0;
    medaritm(v, &m, n);
    int u[50], j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] > m)
        {
            u[j++] = v[i];
        }
    }
    printf("Numarul de mere trimis: %d\n", sumaelem(u, n));

    return EXIT_SUCCESS;
}