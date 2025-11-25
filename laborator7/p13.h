#ifndef P13_H
#define P13_H

#include <stddef.h>

typedef unsigned int natural;
typedef double real;

void *citireVectorInt(size_t n);
void afisareVectorInt(natural *v, size_t n);
natural sumacif(natural x);
natural *VectorSumCif(natural *v, size_t n);
natural ValMax(natural *v, size_t n);

#endif