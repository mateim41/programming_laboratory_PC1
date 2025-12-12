#ifndef P11_H
#define P11_H

#include <stddef.h>

struct COMPLEX
{
    double real, imag;
};
typedef struct COMPLEX complex;

void *xmalloc(const size_t size);
complex *citireNR();
complex *suma(const complex *nr1, const complex *nr2);
complex *produs(const complex *nr1, const complex *nr2);
complex *conjugat(const complex *nr);
double modul(const complex *nr);

// p12

complex **citireSirImaginar(const size_t lungime_sir);
complex *sumaSir(const complex **z, const size_t lungime_sir, const int contor);
complex *produsSir(const complex **z, const size_t lungime_sir);
double *modulSir(const complex **z, const size_t lungime_sir);
double *argumenteSir(const complex **z, const size_t lungime_sir);
void dealocare(complex ***z, const size_t lungime_sir);

#endif