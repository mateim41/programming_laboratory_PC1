#include <stdio.h>
#include <math.h>
#include "p12.h"

float ma(int a, int b, int c)
{
    return (a + b + c) / 3.f;
}
float mg(int a, int b, int c)
{
    return sqrt(a * b * c);
}
int Min(int a, int b, int c)
{
    int m = a;
    if (m > b)
    {
        m = b;
    }
    if (m > c)
    {
        m = c;
    }
    return m;
}
int Max(int a, int b, int c)
{
    int m = a;
    if (m < b)
    {
        m = b;
    }
    if (m < c)
    {
        m = c;
    }
    return m;
}
void afisare(float ma, float mg, int Min, int Max)
{
    printf("Media aritmetica este %lf\n", ma);
    printf("Media geometrica este %lf\n", mg);
    printf("Minimul este %d\n", Min);
    printf("Maximul este %d\n", Max);
}