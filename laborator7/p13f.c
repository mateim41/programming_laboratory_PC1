#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "p13.h"
#include "alocare.h"

// citirea unui vector cu nr intregi
void *citireVectorInt(size_t n)
{
    natural *v = (natural *)xmalloc(n * sizeof(*v));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    return v;
}

// afisarea unui vector cu nr intregi
void afisareVectorInt(natural *v, size_t n)
{
    printf("A = (");
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            printf("%d, ", *(v + i));
        }
        else
        {
            printf("%d)\n", *(v + i));
        }
    }
}

// suma cifrelor unui numar
natural sumacif(natural x)
{
    natural s = 0;
    while (x)
    {
        natural c = x % 10;
        x /= 10;
        s += c;
    }
    return s;
}

// vectorul cu suma cifrelor fiecarui numar
natural *VectorSumCif(natural *v, size_t n)
{
    natural *scif = (natural *)xmalloc(n * sizeof(*scif));
    for (int i = 0; i < n; i++)
    {
        natural s = sumacif(v[i]);
        scif[i] = s;
    }
    return scif;
}

// caut valoarea maxima a scif
natural ValMax(natural *v, size_t n)
{
    int Max = 0;
    int imax = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(v + i) > Max)
        {
            Max = *(v + i);
            imax = i;
        }
    }
    return imax;
}