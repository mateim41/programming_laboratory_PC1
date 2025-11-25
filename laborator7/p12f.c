#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>

#include "p12.h"
#include "alocare.h"

// citirea unui vector de nr naturale
void *pcitireVectorInt(size_t n)
{
    NATURAL *v = (NATURAL *)xmalloc(n * sizeof(*v));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    return v;
}

// afisarea unui vector de nr naturale
void pafisareVectorInt(NATURAL *a, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
    printf("\n");
}

// afisarea unui vector de nr reale
void pafisareVectorReal(REAL *a, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%lf ", *(a + i));
    }
    printf("\n");
}

// calcularea mediei geometrice a elementelor unui vector
double mediegeometrica(REAL *v, size_t n)
{
    double p = 1;
    for (int i = 0; i < n; i++)
    {
        p *= v[i];
    }
    return pow(p, 1.0 / n);
}

// calculam rata de modificare de la o zi la alta
double *rataZilnicaDeModif(NATURAL *v, size_t n, NATURAL celinit)
{
    REAL *rata = (REAL *)xmalloc(n * sizeof(*rata));
    rata[0] = (double)v[0] / celinit;
    for (int i = 1; i < n; i++)
    {
        rata[i] = (double)v[i] / v[i - 1];
    }
    return rata;
}