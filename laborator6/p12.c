#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double b = 0;
    int a = 0;
    printf("Cele doua numere sunt: ");
    scanf("%d %lf", &a, &b);
    double *pb = &b;
    int *pa = &a;
    printf("Suma numerelor %d + %lf = %lf\n", *pa, *pb, (*pa + *pb));

    return EXIT_SUCCESS;
}