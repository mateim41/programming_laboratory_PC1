#include <stdio.h>
#include <stdlib.h>

#include "p11.h"

int main(void)
{
    fractie p, q;
    printf("Cititi cele doua fractii:\n");
    scanf("%d %d", &p.x, &p.y);
    printf("\n");
    scanf("%d %d", &q.x, &q.y);
    printf("\n");

    printf("Inversa lui p:\n");
    afisare(inversa_fractie(p));

    printf("Inversa lui q:\n");
    afisare(inversa_fractie(q));

    printf("Suma celor doua fractii:\n");
    fractie S = suma(p, q);
    afisare(S);

    printf("Diferenta celor doua fractii:\n");
    fractie neg_q = {.x = -q.x, .y = q.y};
    afisare(suma(p, neg_q));

    printf("Produsul celor doua matrici este:\n");
    fractie P = produs(p, q);
    afisare(P);

    return EXIT_SUCCESS;
}