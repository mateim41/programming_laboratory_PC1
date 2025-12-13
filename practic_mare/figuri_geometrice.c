#include <stdio.h>
#include <stdlib.h>

#include "figuri_geometrice.h"

int main(void)
{
    size_t nr_poligoane;
    printf("Introduceti numarul de poligoane: ");
    scanf("%zd", &nr_poligoane);

    double p_min; // perimetrul minim
    printf("Perimetrul minim pentru eligibilitate: ");
    scanf("%lf", &p_min);

    printf("Cititi varfurile poligoanelor:\n");
    poligon **formaGeom = citirePoligon(nr_poligoane);
    printf("\n");

    double *perimetru_forme = perimetruPoligoane((const poligon **)formaGeom, nr_poligoane);
    printf("Perimetrul fiecarui poligon este: ");
    for (int i = 0; i < nr_poligoane; i++)
    {
        printf("%lf ", *(perimetru_forme + i));
    }
    printf("\n");

    punct *G = medieCentruGreutate((const poligon **)formaGeom, nr_poligoane);
    printf("Centrul de greutate este: G(%lf,%lf)\n\n", G->x, G->y);

    size_t nrPolgEligibil = 0;
    int *polg_eligibl = poligoaneEligibile(perimetru_forme, nr_poligoane, p_min, &nrPolgEligibil);
    if (polg_eligibl != NULL)
    {
        printf("Poligoanele eligibile sunt: ");
        for (int i = 0; i < nrPolgEligibil; i++)
        {
            printf("%d ", *(polg_eligibl + i));
        }
        printf("\n");
    }

#pragma region cleanup
    dealocare((poligon ***)&formaGeom, nr_poligoane);
    free(perimetru_forme);
    perimetru_forme = NULL;
    free(G);
    G = NULL;
    free(polg_eligibl);
    polg_eligibl = NULL;
#pragma endregion
    return EXIT_SUCCESS;
}