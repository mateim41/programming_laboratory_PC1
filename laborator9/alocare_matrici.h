#ifndef ALOCARE_MATRICI_H
#define ALOCARE_MATRICI_H

#include <stddef.h>

void **alocareMatrice(const size_t nrlinii, const size_t nrcoloane, const size_t elemSize);
void dealocareMatrice(void ***matrix, const size_t nrlinii);

#endif