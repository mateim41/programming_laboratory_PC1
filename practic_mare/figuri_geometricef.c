#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "figuri_geometrice.h"

void *xmalloc(const size_t size);
void *xcalloc(const size_t nrElem, const size_t size);
poligon **citirePoligon(const size_t nr_poligoane)
{
    poligon **formaGeom = (poligon **)xmalloc(nr_poligoane * sizeof(*formaGeom));
    for (int i = 0; i < nr_poligoane; i++)
    {
        formaGeom[i] = (poligon *)xmalloc(sizeof(poligon));
        scanf("%zd", &formaGeom[i]->nr_varfuri);

        formaGeom[i]->vector_varfuri = (punct *)xmalloc(formaGeom[i]->nr_varfuri * sizeof(punct));
        for (int j = 0; j < formaGeom[i]->nr_varfuri; j++)
        {
            punct *temp = &formaGeom[i]->vector_varfuri[j];
            scanf("%lf %lf", &temp->x, &temp->y);
        }
    }
    return formaGeom;
}
void dealocare(poligon ***formaGeom, const size_t nr_poligoane)
{
    if (formaGeom == NULL || *formaGeom == NULL)
    {
        return;
    }
    poligon **f = *formaGeom;
    for (int i = 0; i < nr_poligoane; i++)
    {
        free(f[i]->vector_varfuri);
        free(f[i]);
    }
    free(f);
    *formaGeom = NULL;
}

double distDintre_2pct(const punct *A, const punct *B)
{
    // Xa Ya
    // Xb Yb
    return sqrt(pow((B->x - A->x), 2) + pow((B->y - A->y), 2));
}
double *perimetruPoligoane(const poligon **formaGeom, const size_t nr_poligoane)
{
    double *perimetru = (double *)xcalloc(nr_poligoane, sizeof(*perimetru));
    for (int i = 0; i < nr_poligoane; i++)
    {
        for (int j = 0; j < formaGeom[i]->nr_varfuri - 1; j++)
        {
            punct *A = &formaGeom[i]->vector_varfuri[j];
            punct *B = &formaGeom[i]->vector_varfuri[j + 1];
            *(perimetru + i) += distDintre_2pct(A, B);
        }
        int k = formaGeom[i]->nr_varfuri;
        *(perimetru + i) += distDintre_2pct(&formaGeom[i]->vector_varfuri[0], &formaGeom[i]->vector_varfuri[k - 1]);
    }
    return perimetru;
}
punct sumaCoordonate(punct *A, const size_t nr_varfuri)
{
    punct S = {S.x = 0, S.y = 0};
    for (int i = 0; i < nr_varfuri; i++)
    {
        S.x += A[i].x;
        S.y += A[i].y;
    }
    return S;
}
punct *medieCentruGreutate(const poligon **formaGeom, const size_t nr_poligoane)
{
    punct *centruDeGreutate = (punct *)xmalloc(sizeof(punct));
    double x_mediu = 0;
    double y_mediu = 0;
    int nr_total_varfuri = 0;
    for (int i = 0; i < nr_poligoane; i++)
    {
        nr_total_varfuri += formaGeom[i]->nr_varfuri;
        punct temp = sumaCoordonate(formaGeom[i]->vector_varfuri, formaGeom[i]->nr_varfuri);
        x_mediu += temp.x;
        y_mediu += temp.y;
    }
    x_mediu /= nr_total_varfuri;
    y_mediu /= nr_total_varfuri;
    centruDeGreutate->x = x_mediu;
    centruDeGreutate->y = y_mediu;
    return centruDeGreutate;
}
int *poligoaneEligibile(const double *perimetruPoligoane, const size_t nr_poligoane, const double p_min, size_t *nrPolgEligibil)
{
    int *polg_eligibl = (int *)xmalloc(nr_poligoane * sizeof(*polg_eligibl));
    int k = 0;
    for (int i = 0; i < nr_poligoane; i++)
    {
        if (*(perimetruPoligoane + i) > p_min)
        {
            *(polg_eligibl + k) = i;
            k++;
        }
    }
    *nrPolgEligibil = k;
    if (k != 0)
    {
        int *p = (int *)realloc(polg_eligibl, k * sizeof(*polg_eligibl));
        if (p == NULL)
        {
            return NULL;
        }
        polg_eligibl = p;
        return polg_eligibl;
    }
    free(polg_eligibl);
    polg_eligibl = NULL;
    return NULL;
}

void *xmalloc(const size_t size)
{
    void *v = malloc(size);
    if (v == NULL)
    {
        fprintf(stderr, "Eroare alocare\n");
        exit(EXIT_FAILURE);
    }
    return v;
}
void *xcalloc(const size_t nrElem, const size_t size)
{
    void *v = calloc(nrElem, size);
    if (v == NULL)
    {
        fprintf(stderr, "Eroare alocare\n");
        exit(EXIT_FAILURE);
    }
    return v;
}