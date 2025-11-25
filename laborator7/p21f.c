#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "p21.h"
#include "alocare.h"

// citim vector de nr reale
void *citireVectorReal(size_t n)
{
    double *v = (double *)xmalloc(n * sizeof(*v));
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", v + i);
    }
    return v;
}

// afisarea vector de nr reale
void afisareVectorReal(double *v, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2lf ", v[i]);
    }
    printf("\n");
}

// calculam normele
double *VectorNorma(double *v, size_t n)
{
    double *norma = (double *)xmalloc(3 * sizeof(*norma));
    double Maxabs = 0;
    double norma1 = 0;
    double norma2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (fabs(*(v + i)) > Maxabs)
        {
            Maxabs = fabs(*(v + i));
        }
        norma1 += fabs(v[i]);
        norma2 += fabs(v[i]) * fabs(v[i]);
    }
    norma[0] = Maxabs;
    norma[1] = norma1;
    norma[2] = sqrt(norma2);
    return norma;
}