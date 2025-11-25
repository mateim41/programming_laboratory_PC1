#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "fct.h"

int main(void)
{
    int n = 0; // maxim 30 de elemente
    printf("Introduceti numarul de elemente: ");
    scanf("%d", &n);
    int v[30];
    citire(v, n);
    ordonare(v, n);
    afisare(v, n);

    return EXIT_SUCCESS;
}