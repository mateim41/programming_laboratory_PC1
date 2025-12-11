#include <stdio.h>
#include <stdlib.h>

#include "angajati2.h"

int main(void)
{
    size_t nr_angajati;
    printf("Introduceti numaraul de angajati ai firmei: ");
    scanf("%zd", &nr_angajati);

    printf("Cititi datele fiecarui angajat:\n");
    angajat *firma = citireInformatii(nr_angajati);

    printf("Pragurile pentru promovare: ");
    double prag_performanta = 0;
    int nr_min_proiecte = 0;
    scanf("%lf %d", &prag_performanta, &nr_min_proiecte);
    printf("\n");

    double *medie_performanta = (double *)xmalloc(nr_angajati * sizeof(*medie_performanta));
    printf("Media de performanta a fiecarui angajat: ");
    for (int i = 0; i < nr_angajati; i++)
    {
        *(medie_performanta + i) = scorMediuPerformanta(firma, i);
        printf("%lf ", *(medie_performanta + i));
    }
    printf("\n");

    size_t nrAngajatiPromo = 0;
    int *promovat = angajatiPromovati(firma, nr_angajati, prag_performanta, nr_min_proiecte, &nrAngajatiPromo);
    printf("ID-ul angajatilor promovati, ordonat descresc in fct de performanta: ");
    for (int i = 0; i < nrAngajatiPromo; i++)
    {
        printf("%d ", *(promovat + i));
    }
    printf("\n");

    printf("Introduceti indexul de proiect: ");
    size_t index_proiect;
    scanf("%zd", &index_proiect);
    statisticaProiect(firma, nr_angajati, index_proiect);

    dealocareStruct((angajat **)&firma, nr_angajati);
    free(medie_performanta);
    medie_performanta = NULL;
    free(promovat);
    promovat = NULL;
    return EXIT_SUCCESS;
}