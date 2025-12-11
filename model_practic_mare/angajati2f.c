#include <stdio.h>
#include <stdlib.h>

#include "angajati2.h"

void *xmalloc(const size_t size);
void citireUnAngajat(angajat *a)
{
    scanf("%d %d", &a->ID, &a->nr_proiecte);
    a->v_performanta = (int *)xmalloc(a->nr_proiecte * sizeof(*a->v_performanta));
    for (int j = 0; j < a->nr_proiecte; j++)
    {
        scanf("%d", &a->v_performanta[j]);
    }
}
angajat *citireInformatii(const size_t nr_angajati)
{
    angajat *firma = xmalloc(nr_angajati * sizeof(*firma));
    for (int i = 0; i < nr_angajati; i++)
    {
        citireUnAngajat(&firma[i]);
    }
    return firma;
}
void dealocareStruct(angajat **firma, const size_t nr_angajati)
{
    if (firma == NULL || *firma == NULL)
    {
        return;
    }
    angajat *firmaReal = *firma;
    for (int i = 0; i < nr_angajati; i++)
    {
        free(firmaReal[i].v_performanta);
    }
    free(firmaReal);
    *firma = NULL;
}

// performanta medie a unui singur angajat
double scorMediuPerformanta(const angajat *firma, const size_t index_angajat)
{
    const angajat *temp = &firma[index_angajat];
    double mediePerformanta = 0;
    for (int i = 0; i < temp->nr_proiecte; i++)
    {
        mediePerformanta += temp->v_performanta[i];
    }
    if (mediePerformanta != 0)
    {
        mediePerformanta /= temp->nr_proiecte;
    }
    return mediePerformanta;
}
// angajatii promovati ordonati descrescator in functie de performanta
int *angajatiPromovati(const angajat *firma, const size_t nr_angajati, const double prag_performanta, const size_t nr_min_proiecte, size_t *nrAngajatiPromovati)
{
    typedef struct
    {
        int ID_promovat;
        double performanta_promovat;
    } candidat;

    candidat *list = (candidat *)xmalloc(nr_angajati * sizeof(candidat));
    int k = 0;
    for (int i = 0; i < nr_angajati; i++)
    {
        // const angajat *crt = &firma[i];
        double med = scorMediuPerformanta(firma, i);
        if (med >= prag_performanta && firma[i].nr_proiecte >= nr_min_proiecte)
        {
            list[k].ID_promovat = firma[i].ID;
            list[k].performanta_promovat = med;
            k++;
        }
    }
    // sortare
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (list[i].performanta_promovat < list[j].performanta_promovat)
            {
                candidat aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
        }
    }
    int *promovatiID = (int *)xmalloc(k * sizeof(*promovatiID));
    for (int i = 0; i < k; i++)
    {
        *(promovatiID + i) = list[i].ID_promovat;
    }
    *nrAngajatiPromovati = k;
    free(list);
    list = NULL;
    return promovatiID;
}
// afisez nr de angajati care au lucrat la un proiect si performanta medie a proiectului
void statisticaProiect(const angajat *firma, const size_t nr_angajati, const size_t index_proiect)
{
    int angajatiPerProiect = 0;
    double performantaMedieProiect = 0;
    for (int i = 0; i < nr_angajati; i++)
    {
        if (index_proiect < firma[i].nr_proiecte)
        {
            angajatiPerProiect++;
            performantaMedieProiect += firma[i].v_performanta[index_proiect];
        }
    }
    if (angajatiPerProiect != 0)
    {
        performantaMedieProiect /= angajatiPerProiect;
        printf("Numarul de angajati care au lucrat la proiectul %zd este %d\n", index_proiect, angajatiPerProiect);
        printf("Media de performanta a proiectului este %lf\n", performantaMedieProiect);
    }
    else
    {
        printf("Niciun angajat nu a lucrat la acest proiect.\n");
    }
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