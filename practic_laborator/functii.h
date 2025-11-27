#ifndef FUNCTII_H
#define FUNCTII_H

#include <stddef.h>

void *citireConsumEnergie(size_t nr_elem);
void afisareVector(double *v, size_t nr_elem);
void calibrareRetea(double *v, size_t nr_elem, double procentPierderi);
double consumCartier(double *v, size_t nr_elem);
// consumul tuturor caselor si nr de gospodarii care au depasit plafonul
void raportSintetic(double *v, size_t nr_elem, double *consumTotal, int *nrGospodarii, double plafonMaxim);

#endif