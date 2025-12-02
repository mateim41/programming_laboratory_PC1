#ifndef TEMA2_H
#define TEMA2_H

#include <stddef.h>

#define NROW 100
#define NCOL 100
typedef int intMatrice[NROW][NCOL];
typedef int intVector[NCOL];

void citireVector(intVector vec, size_t n);
void afisareVector(intVector vec, size_t n);
void citireMatrice(intMatrice mat, size_t n, size_t m);
void afisareMatrice(intMatrice mat, size_t n, size_t m);
void sumaMatrici(intMatrice S, intMatrice A, size_t n, size_t m, intMatrice B, size_t p, size_t q);
void produsMatrici(intMatrice P, intMatrice A, size_t n, size_t m, intMatrice B, size_t p, size_t q);
void transpusaMatrice(intMatrice T, intMatrice A, size_t n, size_t m);

void *xmalloc(size_t size);
void **alocareMatrice(size_t n, size_t m, size_t elemSize);
int **citireMatrice_dinamic(size_t n, size_t m);
void afisareMatrice_dinamic(int **matrix, size_t n, size_t m);
void dealocareMatrice(void ***matrix);
int **matrice_unitate(size_t n, size_t m);
int **produsMatrice_dinamic(int **A, size_t n, size_t m, int **B, size_t p, size_t q);
void transpusaMatrice_dinamic(int **T, int **A, size_t n, size_t m);

#endif