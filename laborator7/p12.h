#ifndef P12_H
#define P12_H

#include <stddef.h>

// defineste tipul NATURAL ca fiind unsigned int
typedef unsigned int NATURAL;

// defineste tipul REAL ca fiind double
typedef double REAL;

void *pcitireVectorInt(size_t n);
void pafisareVectorInt(NATURAL *a, size_t n);
void pafisareVectorReal(REAL *a, size_t n);
double mediegeometrica(REAL *v, size_t n);
double *rataZilnicaDeModif(NATURAL *a, size_t n, NATURAL celinit);

#endif