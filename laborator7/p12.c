#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "p12.h"
#include "afisare.h"
#include "alocare.h"

int main(void)
{
    printf("Valoarea inițială a numărului de celule din cultură: ");
    NATURAL nrcelule;
    scanf("%d", &nrcelule);

    printf("Numarul de zile de observare a culturii: ");
    NATURAL nrzile;
    scanf("%d", &nrzile);

    printf("Numarul de celule: ");
    NATURAL *zile = pcitireVectorInt(nrzile);

    printf("\n");

    printf("Rata zilnică de modificare: ");
    REAL *ratamodif = rataZilnicaDeModif(zile, nrzile, nrcelule);
    afisare(ratamodif, nrzile, sizeof(*ratamodif), afisare_real3);

    printf("Media geometrica: ");
    REAL mg = mediegeometrica(ratamodif, nrzile);
    printf("%.3lf\n", mg);

    printf("Rata medie de modificare: ");
    REAL ratamedie = (mg - 1) * 100;
    printf("%.3lf%%\n", ratamedie);

    memset(zile, 0, nrzile);
    memset(ratamodif, 0, nrzile);
    free(zile);
    free(ratamodif);
    zile = nullptr;
    ratamodif = nullptr;

    return EXIT_SUCCESS;
}