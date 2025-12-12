#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "p11.h"

int main(void)
{
    complex *z1 = xmalloc(sizeof(*z1));
    complex *z2 = xmalloc(sizeof(*z2));
    printf("Cititi cele doua numere complexe:\n");
    scanf("%lf %lf\n", &z1->real, &z1->imag);
    scanf("%lf %lf", &z2->real, &z2->imag);

    complex *c1 = produs(&(complex){z1->real * 2, z1->imag * 2}, &(complex){z2->real * 3.2, z2->imag * 3.2});
    printf("z1 * 2 + z2 * 3.2 = %lf + %lfi\n", c1->real, c1->imag);

    complex *c2 = produs(&(complex){z1->real * 3.5 + 1, z1->imag * 3.5}, z2);
    printf("(z1 * 3.5 + 1) * z2 = %lf + %lfi\n", c2->real, c2->imag);

    /*
        z2 = a2 + b2i
        z2 = 1/a2 + 1/b2i
    */
    complex *c3 = produs(z1, &(complex){z2->real / (pow(z2->real, 2) + pow(z2->imag, 2)), -z2->imag / pow(z2->real, 2) + pow(z2->imag, 2)});
    printf("z1 / z2 = %lf + %lfi\n", c3->real, c3->imag);

    free(z1);
    z1 = NULL;
    free(z2);
    z2 = NULL;
    free(c1);
    c1 = NULL;
    free(c2);
    c2 = NULL;
    free(c3);
    c3 = NULL;
    return EXIT_SUCCESS;
}