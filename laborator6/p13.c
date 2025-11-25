#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a = 0, b = 0;
    printf("Cele doua numere sunt: ");
    scanf("%d %d", &a, &b);
    int *pa = &a;
    int *pb = &b;
    int max;
    if (*pa < *pb)
        max = *pb;
    else
        max = *pa;
    printf("Maximul este: %d\n", max);

    return EXIT_SUCCESS;
}