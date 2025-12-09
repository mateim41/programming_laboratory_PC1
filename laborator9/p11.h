#ifndef P11_H
#define P11_H

#include <stddef.h>

void **alocareMatrice(const size_t nrlinii, const size_t nrcoloane, const size_t elemSize);
void dealocareMatrice(void ***matrix, const size_t nrlinii);

int **citireMatrice(const size_t nrlinii, const size_t nrcoloane);
void afisareMatrice(const int **matrix, const size_t nrlinii, const size_t nrcoloane);

void ordonareMatrice(int **matrix, const size_t nrlinii, const size_t nrcoloane);

#endif