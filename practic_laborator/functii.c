#include <stdio.h>
#include <stdlib.h>

#include "functii.h"
#include "alocare.h"

void *citireConsumEnergie(size_t nr_elem)
{
    double *v = (double *)xcalloc(nr_elem, sizeof(*v));
    for (int i = 0; i < nr_elem; i++)
    {
        scanf("%lf", v + i);
    }
    return v;
}
void afisareVector(double *v, size_t nr_elem) // 1 2 3 4 5
{
    printf("[");
    for (int i = 0; i < nr_elem; i++)
    {
        if (i != nr_elem - 1)
        {
            printf("%.2lf, ", *(v + i));
        }
        else
        {
            printf("%.2lf]\n", *(v + i));
        }
    }
}
void calibrareRetea(double *v, size_t nr_elem, double procentPierderi)
{
    for (int i = 0; i < nr_elem; i++)
    {
        *(v + i) += *(v + i) * procentPierderi;
    }
}
double consumCartier(double *v, size_t nr_elem)
{
    double s = 0;
    for (int i = 0; i < nr_elem; i++)
    {
        s += *(v + i);
    }
    return s;
}
// consumul tuturor caselor si nr de gospodarii care au depasit plafonul
void raportSintetic(double *v, size_t nr_elem, double *consumTotal, int *nrGospodarii, double plafonMaxim)
{
    *consumTotal = consumCartier(v, nr_elem);
    for (int i = 0; i < nr_elem; i++)
    {
        if (*(v + i) > plafonMaxim)
        {
            *nrGospodarii += 1;
        }
    }
}
