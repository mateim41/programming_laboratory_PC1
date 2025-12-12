#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "p11.h"

void *xmalloc(const size_t size);

complex *citireNR()
{
    complex *nr = xmalloc(sizeof(*nr));
    scanf("%lf %lf", &nr->real, &nr->imag);
    return nr;
}
complex *suma(const complex *nr1, const complex *nr2)
{
    complex *s = xmalloc(sizeof(*s));
    s->real = nr1->real + nr2->real;
    s->imag = nr1->imag + nr2->imag;
    return s;
}
complex *produs(const complex *nr1, const complex *nr2)
{
    /*
       z1 = a1 + b1i
       z2 = a2 + b2i
       z1 * z2 = a1a2 + a1b2i + a2b1i - b1b2
               = a1a2 - b1b2 + (a1b2 + a2b1)i;
    */
    complex *p = xmalloc(sizeof(*p));
    p->real = nr1->real * nr2->real - nr1->imag * nr2->imag;
    p->imag = nr1->real * nr2->imag + nr1->imag * nr2->real;
    return p;
}
complex *conjugat(const complex *nr)
{
    complex *c = xmalloc(sizeof(*c));
    c->real = nr->real;
    c->imag = -nr->imag;
    return c;
}
double modul(const complex *nr)
{
    return sqrt(pow(nr->real, 2) + pow(nr->imag, 2));
}

complex **citireSirImaginar(const size_t lungime_sir)
{
    complex **z = xmalloc(lungime_sir * sizeof(*z));
    for (int i = 0; i < lungime_sir; i++)
    {
        z[i] = citireNR();
    }
    return z;
}
void dealocare(complex ***z, const size_t lungime_sir)
{
    if (z == NULL || *z == NULL)
    {
        return;
    }
    complex **a = *z;
    for (int i = 0; i < lungime_sir; i++)
    {
        free(a[i]);
    }
    free(a);
    *z = NULL;
}
// in functie de contor returnam suma indecsilor impari sau a indecsilor pari
complex *sumaSir(const complex **z, const size_t lungime_sir, const int contor)
{
    complex *s = (complex *)xmalloc(sizeof(*s));
    s->real = 0;
    s->imag = 0;
    for (int i = contor; i < lungime_sir; i += 2)
    {
        s->real += z[i]->real;
        s->imag += z[i]->imag;
    }
    return s;
}
double *modulSir(const complex **z, const size_t lungime_sir)
{
    double *vector_module = (double *)xmalloc(lungime_sir * sizeof(*vector_module));
    for (int i = 0; i < lungime_sir; i++)
    {
        vector_module[i] = modul(z[i]);
    }
    return vector_module;
}
double *argumenteSir(const complex **z, const size_t lungime_sir)
{
    // arg(z) = arctg(b / a)
    double *vectorArgumente = (double *)xmalloc(lungime_sir * sizeof(*vectorArgumente));
    for (int i = 0; i < lungime_sir; i++)
    {
        if (z[i]->real != 0)
            *(vectorArgumente + i) = atan2(z[i]->imag, z[i]->real);
        else
            *(vectorArgumente + i) = 0;
    }
    return vectorArgumente;
}

void *xmalloc(const size_t size)
{
    void *v = malloc(size);
    if (v == NULL)
    {
        fprintf(stderr, "Eroare alocare\n");
        exit(EXIT_FAILURE);
    }
    return v;
}