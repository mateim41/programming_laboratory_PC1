#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b, c, Max;
    printf("Introduceti cele trei numere: ");
    scanf("%d %d %d", &a, &b, &c);
    if (a > b)
        Max = a;
    else
        Max = b;
    if (Max > c)
        printf("Numarul maxim este %d\n", Max);
    else
        printf("Numarul maxim este %d\n", c);

    return EXIT_SUCCESS;
}