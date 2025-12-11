#include <stdio.h>
#include <stdlib.h>

#include "angajati3.h"

int main(void)
{
    size_t nr_angajati;
    printf("Numarul de angajati ai firmei: ");
    scanf("%zd", &nr_angajati);

    printf("Datele angajatilor:\n");
    angajat **firma = citireFirma(nr_angajati);

    int nr_min_proiecte = 0;
    double prag_performanta = 0;
    printf("Pragul de performanta si nr_min_proiecte pentru a fi promovat: ");
    scanf("%lf %d", &prag_performanta, &nr_min_proiecte);

    size_t nrPromovati = 0;
    int *promovatiID = angajatiPromovati((const angajat **)firma, nr_angajati, prag_performanta, nr_min_proiecte, &nrPromovati);
    printf("ID-ul angajatilor promovati, ordonati descresc in functie de performanta: ");
    for (int i = 0; i < nrPromovati; i++)
    {
        printf("%d ", *(promovatiID + i));
    }
    printf("\n");

    printf("Indexul de proiect pentru care se face statistica: ");
    int index_proiect;
    scanf("%d", &index_proiect);
    statisticaProiect((const angajat **)firma, nr_angajati, index_proiect);

    dealocare(&firma, nr_angajati);
    free(promovatiID);
    promovatiID = NULL;
    return EXIT_SUCCESS;
}