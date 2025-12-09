#ifndef P12_3_H
#define P12_3_H

#include <stddef.h>

int **citireMatrice(const size_t nrlinii, const size_t nrcoloane);
void afisareMatrice(const int **matrix, const size_t nrlinii, const size_t nrcoloane);

void primaLinieCresc(int **matrix, const size_t nrlinii, const size_t nrcoloane);
void primaColoanaCresc(int **matrix, const size_t nrlinii, const size_t nrcoloane);
void diagPrincCresc(int **matrix, const size_t nrlinii, const size_t nrcoloane);
void diagSecCresc(int **matrix, const size_t nrlinii, const size_t nrcoloane);
void LiniaMedianaVerticala(int **matrix, const size_t nrlinii, const size_t nrcoloane);

#endif