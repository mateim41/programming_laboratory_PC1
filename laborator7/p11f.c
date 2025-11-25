#include <stdio.h>

#include "p11.h"
#include "alocare.h"

// Citirea unui vector de intregi
int *pcitireVector2(int n)
{
    int *v = (int *)xmalloc(n * sizeof(*v)); // in loc de sizeof(int)
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    return v;
}

// Afișarea vectorilor
void pafisareVectorIntregi(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void pafisareVectorReali(double *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%lf ", a[i]);
    }
    printf("\n");
}

// Calcularea vectorului cu valorile medii (folosind media aritmetică)
double *vectorMedie(int *a, int *b, int n)
{
    double *v = (double *)xmalloc(n * sizeof(*v));
    for (int i = 0; i < n; i++)
    {
        v[i] = mediaAritmeticaIntregi(a[i], b[i]);
    }
    return v;
}

// Calcularea mediei aritmetice a valorilor elementelor unui vector
double mediaAritmeticaVector(double *a, int n)
{
    return sumaVectorReali(a, n) / 2.0;
}

// Calcularea mediei aritmetice a două numere întregi
double mediaAritmeticaIntregi(int a, int b)
{
    return (a + b) / 2.0;
}

// Calcularea sumei valorilor elementelor unui vector de reali
double sumaVectorReali(double *a, int n)
{
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
    }
    return s;
}