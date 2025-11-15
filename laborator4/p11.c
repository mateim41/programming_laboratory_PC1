#include <stdio.h>
#include <stdlib.h>
#include "p11.h"

int main(void)
{
    double a, b;
    printf("Cele doua numere sunt: ");
    scanf("%lf %lf", &a, &b);
    f1(&a, &b);
    printf("Numerele modificate sunt: %lf, %lf\n", a, b);

    return EXIT_SUCCESS;
}