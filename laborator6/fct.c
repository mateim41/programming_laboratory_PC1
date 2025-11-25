#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "fct.h"

void citire(int *v, size_t n)
{
    for (int *p = v; p < v + n; p++)
    {
        scanf("%d", p);
    }
}
void afisare(int *v, size_t n)
{
    for (int *p = v; p < v + n; p++)
    {
        printf("%d ", *p);
    }
    printf("\n");
}
unsigned int suma(int *v, int *u, size_t n, size_t t)
{
    unsigned int s = 0;
    for (int j = 0; j < t; j++)
    {
        v[u[j]] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        s += v[i];
    }
    return s;
}
void interschimb(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}
void ordonare(int *v, size_t n)
{
    for (int *p = v; p < v + n - 1; p++)
    {
        for (int *u = p + 1; u < v + n; u++)
        {
            if (*p > *u)
            {
                interschimb(p, u);
            }
        }
    }
}
