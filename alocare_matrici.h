#ifndef ALOCARE_MATRICI_H
#define ALOCARE_MATRICI_H

#include <stddef.h>

void *xmalloc(size_t size);

void **alocareMatrice_fragmented(size_t n, size_t m, size_t elemSize);
void **alocareMatrice_contiguous(size_t n, size_t m, size_t elemSize);

void dealocareMatrice_fragmented_mod1(void ***matrix, size_t n);
void dealocareMatrice_fragmented_mod2(void **matrix, size_t n);

void dealocareMatrice_contiguous_mod1(void ***matrix);
void dealocareMatrice_contiguous_mod2(void **matrix);

int **citireMatrice(size_t n, size_t m);
void afisareMatrice_int(int **matrix, size_t n, size_t m);

#endif