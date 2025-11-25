#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char z;
    int m;
    double fx;
    printf("Introduceti valorile: ");
    scanf("%c %d %lf", &z, &m, &fx);
    printf("Adresa lui z este = %p\n", &z);
    printf("Adresa lui m este = %p\n", &m);
    printf("Adresa lui fx este = %p\n", &fx);

    printf("\n");

    printf("Valoarea lui z este = %c\n", *(&z));
    printf("Valoarea lui m este = %d\n", *(&m));
    printf("Valoarea lui fx este = %lf\n", *(&fx));

    printf("\n");

    char *c = &z;
    int *nr = &m;
    double *nrr = &fx;

    printf("Valoarea pointerului cu adresa lui m este = %p\n", c);
    printf("Valoarea pointerului cu adresa lui z este = %p\n", nr);
    printf("Valoarea pointerului cu adresa lui fx este = %p\n", nrr);

    printf("\n");

    printf("Valoarea de la adresa lui z este = %c\n", *c);
    printf("Valoarea de la adresa lui m este = %d\n", *nr);
    printf("Valoarea de la adresa lui fx este = %lf\n", *nrr);

    return EXIT_SUCCESS;
}