#ifndef P12_H
#define P12_H

#include <stddef.h>

#define NROW 5
#define NCOL 10
typedef int intMatrice[NROW][NCOL];
typedef int intVector[NCOL];

void citireVector(intVector vec, size_t nr_elem);
void afisareVector(intVector vec, size_t nr_elem);
void citireMatrice(intMatrice mat, size_t n, size_t m);
void afisareMatrice(intMatrice mat, size_t n, size_t m);
// m - nr coloanei
int ConsumColoana(intMatrice mat, size_t n, size_t m);
// m = nr coloanei pe care facem calculul
// consumTotal = consumul de apa de pe toata coloanas
double redistribuire(intMatrice mat, size_t n, size_t m, int consumTotal, int pierderiColoana);

#endif