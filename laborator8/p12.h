#ifndef P12_H
#define P12_H

#include <stddef.h>

#define NROW 5
#define NCOL 10

typedef int IntVector[NCOL];
typedef int IntMatrice[NROW][NCOL];

void citireVec(IntVector vec, size_t n);
void afisareVec(IntVector vec, size_t n);
void citireMat(IntMatrice mat, size_t n, size_t m);
void afisareMat(IntMatrice mat, size_t n, size_t m);
int sumacol(IntMatrice mat, size_t n, size_t m); // m coloana pe care facem suma
int pierderi(IntVector vec, size_t i, int atot);
double redistribuire(IntMatrice mat, size_t n, size_t m, int p, int scol);
// a1 + (a1/c)*p;
// c = total apa pe coloana
// p = pierderea

#endif