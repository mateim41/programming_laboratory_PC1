#include <stdio.h>
#include <stdlib.h>
#include "p14.h"

int main(void)
{
    int a, b, c;
    printf("Cele trei numere intregi sunt: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("Tr: %d\n", verif(a, b, c));
    printf("Tr ech: %d\n", trech(a, b, c));
    printf("Tr is: %d\n", tris(a, b, c));
    printf("Tr dr: %d\n", trdr(a, b, c));

    return EXIT_SUCCESS;
}