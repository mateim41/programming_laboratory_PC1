#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "p13.h"
#include "alocare.h"
#include "afisare.h"

int main(void)
{
    printf("Cate numere naturale citim: ");
    natural n;
    scanf("%d", &n);
    printf("Elementele citite: ");
    natural *v = citireVectorInt(n);

    printf("Suma cifrelor fiecarui element: ");
    natural *w = VectorSumCif(v, n);
    afisare(w, n, sizeof(*w), afisare_int);
    printf("\n");
    afisareVectorInt(w, n);

    printf("Numarul care are suma cifrelor cea mai mare: ");
    int indice = ValMax(w, n);
    printf("%d\n", v[indice]);

    memset(v, 0, n);
    memset(w, 0, n);
    free(v);
    free(w);
    v = nullptr;
    w = nullptr;

    return EXIT_SUCCESS;
}