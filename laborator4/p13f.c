#include <stdio.h>
#include <math.h>
#include "p13.h"

void f1(void)
{
    printf("Programul calculeaza suma unui sir si afiseaza valoarea sumei impartite la un nr intreg.\n");
}
int suma(void)
{
    int x, s = 0;
    scanf("%d", &x);
    while (x != 0)
    {
        s += x;
        scanf("%d", &x);
    }
    return s;
}
void afisare(int a)
{
    printf("valoarea este: %d\n", a);
}
double rezultat(int s, int a)
{
    double r = (double)s / a;
    return r;
}