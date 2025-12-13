#ifndef FIGURI_GEOMETRICE_H
#define FIGURI_GEOMETRICE_H

#include <stddef.h>

struct PUNCT
{
    double x, y;
};
typedef struct PUNCT punct;
struct POLIGON
{
    size_t nr_varfuri;
    punct *vector_varfuri;
};
typedef struct POLIGON poligon;

poligon **citirePoligon(const size_t nr_poligoane);
void dealocare(poligon ***formaGeom, const size_t nr_poligoane);
double *perimetruPoligoane(const poligon **formaGeom, const size_t nr_poligoane);
punct *medieCentruGreutate(const poligon **formaGeom, const size_t nr_poligoane);
int *poligoaneEligibile(const double *perimetruPoligoane, const size_t nr_poligoane, const double p_min, size_t *nrPolgEligibil);

#endif