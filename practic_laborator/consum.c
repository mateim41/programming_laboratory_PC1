#include <stdio.h>
#include <stdlib.h>

#include "functii.h"

int main(void)
{
    size_t nrCase;
    scanf("%zd", &nrCase);

    double plafonMaxim;
    scanf("%lf", &plafonMaxim);

    double procentPierderi;
    scanf("%lf", &procentPierderi);

    double *vectorConsum = citireConsumEnergie(nrCase);

    printf("Numarul de case: %zd\n\n", nrCase);
    printf("Plafon de consum: %.2lf kWh\n\n", plafonMaxim);
    printf("Procent pierderi: %.2lf%%\n\n\n", procentPierderi * 100);
    printf("Consumul initial al caselor monitorizate: ");
    afisareVector(vectorConsum, nrCase);
    printf("\n");

    calibrareRetea(vectorConsum, nrCase, procentPierderi);
    printf("Consumul ajustat cu pierderile din retea: ");
    afisareVector(vectorConsum, nrCase);
    printf("\n");

    int nrGospodarii = 0;
    double consumTotal = 0;
    raportSintetic(vectorConsum, nrCase, &consumTotal, &nrGospodarii, plafonMaxim);
    printf("Consumul total din cartier: %.2lf kWh\n\n", consumTotal);
    printf("Clienți care au depășit plafonul: %d\n\n\n", nrGospodarii);

    free(vectorConsum);
    vectorConsum = nullptr;
    printf("Memoria a fost eliberată. Program încheiat.\n");
    return EXIT_SUCCESS;
}