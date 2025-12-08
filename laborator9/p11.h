#ifndef P11_H
#define P11_H

#include <stddef.h>

void **alocareMatrice(const size_t n, const size_t m, const size_t elemSize);
void dealocareMatrice(void ***matrix, size_t n);

int **citireMatrice(const size_t n, const size_t m);
void afisare_matrice(const int **matrix, const size_t n, const size_t m);

void ordonareMatrice(int **matrix, const size_t n, const size_t m);

#endif