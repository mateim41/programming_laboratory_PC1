#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "p223.h"
#include "alocare.h"

// citirea multimlor
double *Citire(size_t n)
{
    double *v = (double *)xmalloc(n * sizeof(*v));
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", v + i);
    }
    return v;
}
// afisare multimilor
void Afisare(double *v, size_t n)
{
    printf("{");
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            printf("%.2lf, ", *(v + i));
        }
        else
        {
            printf("%.2lf}\n", *(v + i));
        }
    }
}
// verif daca un elem apartine unei multimi
int ApartineMultime(double *v, size_t n, double x)
{
    for (int i = 0; i < n; i++)
    {
        if (x == *(v + i))
            return 1;
    }
    return 0;
}
// reuniunea a doua multimi
double *Reuniune(double *A, double *B, size_t n, size_t m, size_t *lungime)
{
    double *R = (double *)xmalloc((m + n) * sizeof(*R));
    size_t card = 0, j = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (ApartineMultime(R, card, *(A + i)) == 0)
        {
            *(R + card++) = *(A + i);
        }
        if (ApartineMultime(R, card, *(B + j)) == 0)
        {
            *(R + card++) = *(B + j++);
        }
    }
    R = xrealloc(R, card * sizeof(*R));
    *lungime = card;
    return R;
}
// intersectia a doua multimi
double *Intersectie(double *A, double *B, size_t n, size_t m, size_t *lungime)
{
    double *I = (double *)xmalloc(n * sizeof(*I));
    size_t card = 0;
    for (int i = 0; i < n; i++)
    {
        if (ApartineMultime(B, m, *(A + i)) && ApartineMultime(I, card, *(A + i)) == 0)
        {
            *(I + card++) = *(A + i);
        }
    }
    I = xrealloc(I, card * sizeof(*I));
    *lungime = card;
    return I;
}
// diferenta simetrica a doua multimi
// elem din A care nu sunt in B si elem din B care nu sunt in A
double *DiferentaSimetrica(double *A, double *B, size_t n, size_t m, size_t *lungime)
{
    double *DS = (double *)xmalloc((m + n) * sizeof(*DS));
    size_t card = 0;
    for (int i = 0; i < n; i++)
    {
        if (ApartineMultime(B, m, *(A + i)) == 0 && ApartineMultime(DS, card, *(A + i)) == 0)
        {
            *(DS + card++) = *(A + i);
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (ApartineMultime(A, n, *(B + j)) == 0 && ApartineMultime(DS, card, *(B + j)) == 0)
        {
            *(DS + card++) = *(B + j);
        }
    }
    DS = xrealloc(DS, card * sizeof(*DS));
    *lungime = card;
    return DS;
}
char *transformareToASCII(long int x, size_t *size)
{
    char *sir = (char *)xcalloc(1, sizeof(*sir));
    if (x < 0)
    {
        sir[0] = '-';
        x = -x;
    }
    int nrcifre = floor(log10(x)) + 1;
    sir = xrealloc(sir, nrcifre + 1);
    long int ogl = 0;
    while (x)
    {
        ogl = ogl * 10 + x % 10;
        x /= 10;
    }
    for (int i = 1; i < nrcifre + 1; i++)
    {
        *(sir + i) = ogl % 10;
        ogl /= 10;
    }
    *size = nrcifre + 1;
    return sir;
}