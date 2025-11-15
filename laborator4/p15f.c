#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "p15.h"

double fx(double x)
{
    if (x <= 2)
    {
        return x * x + 3 * x + 5;
    }
    else if (x < 8)
    {
        return 3 * x;
    }
    else
        return exp(x) + 2;
}
double gxy(double x, double y)
{
    return 3 * x * x + (sin(x) / pow(y, 0.25));
}
void afisare(double y)
{
    double x;
    float cnt;
    printf("Pasul este: ");
    scanf("%f", &cnt);
    for (x = 0; x <= 10; x += cnt)
    {
        printf("Valoarea functiilor f si g este: %lf, %lf\n", fx(x), gxy(x, y));
    }
}