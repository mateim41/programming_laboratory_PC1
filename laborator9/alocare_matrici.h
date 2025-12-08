#ifndef ALOCARE_MATRICI_H
#define ALOCARE_MATRICI_H

#include <stddef.h>

void **alocare_matrice(const size_t n, const size_t m, const size_t elemSize);
void dealocare_matrice(void ***matrix);

#endif