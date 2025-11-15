#include <stdio.h>
#include <stdlib.h>
#include "p13.h"

int main(void)
{
    int s, y;
    f1();
    s = suma();
    afisare(s);
    printf("Introduceti numarul intreg: ");
    scanf("%d", &y);
    double r = rezultat(s, y);
    printf("%lf\n", r);

    return EXIT_SUCCESS;
}