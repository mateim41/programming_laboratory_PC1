#include <stdio.h>
#include <stdlib.h>

#include "angajati3.h"

typedef struct
{
    int id_promovat;
    double performanta_promovat; // media performantei unui singur angajat
} candidat;

void *xmalloc(const size_t size);
void *xcalloc(const size_t nr_elem, const size_t size);
void *xrealloc(void *v, const size_t size);
int compare(const void *p1, const void *p2);

angajat *citireAngajat()
{
    angajat *f = (angajat *)xmalloc(sizeof(*f));
    scanf("%d %d", &f->ID, &f->nr_proiecte);
    f->v_performanta = (int *)xmalloc(f->nr_proiecte * sizeof(int));
    for (int i = 0; i < f->nr_proiecte; i++)
    {
        scanf("%d", &f->v_performanta[i]);
    }
    return f;
}
angajat **citireFirma(const size_t nr_angajati)
{
    angajat **firma = (angajat **)xmalloc(nr_angajati * sizeof(*firma));
    for (int i = 0; i < nr_angajati; i++)
    {
        firma[i] = citireAngajat();
    }
    return firma;
}
void dealocare(angajat ***firma, const size_t nr_angajati)
{
    if (firma == NULL || *firma == NULL)
    {
        return;
    }
    angajat **f = *firma;
    for (int i = 0; i < nr_angajati; i++)
    {
        if (f[i]->v_performanta != NULL)
        {
            free(f[i]->v_performanta);
        }
        free(f[i]);
    }
    free(f);
    *firma = NULL;
}

double scorMediuPerformanta(const angajat **firma, const size_t index_angajat)
{
    double mediu = 0;
    const angajat *temp = firma[index_angajat];
    for (int i = 0; i < temp->nr_proiecte; i++)
    {
        mediu += temp->v_performanta[i];
    }
    if (mediu != 0)
    {
        mediu /= temp->nr_proiecte;
    }
    return mediu;
}
int *angajatiPromovati(const angajat **firma, const size_t nr_angajati, const double prag_performanta, const int nr_min_proiecte, size_t *nrPromovati)
{
    candidat *f = (candidat *)xmalloc(nr_angajati * sizeof(*f));
    int k = 0;
    for (int i = 0; i < nr_angajati; i++)
    {
        const angajat *temp = firma[i];
        double mediePerformance = scorMediuPerformanta(firma, i);
        if (mediePerformance >= prag_performanta && temp->nr_proiecte >= nr_min_proiecte)
        {
            f[k].id_promovat = temp->ID;
            f[k].performanta_promovat = mediePerformance;
            k++;
        }
    }
    // sortare
    /*
        daca spre exemplu aveam si un pointer
        struct
        {
            int *pointer;
        }
        trebuia sa fac dealocarea memorie pentru pointer
        for(int i = k;i < nr_angajati; i++)
        {
            free(f[i].pointer);
        }

            dupa
        f = xrealloc(f, k * sizeof(*f))
    */
    f = (candidat *)xrealloc(f, k * sizeof(*f));
    *nrPromovati = k;
    qsort(f, k, sizeof(candidat), compare);
    int *promovatiID = (int *)xmalloc(k * sizeof(*promovatiID));
    for (int i = 0; i < k; i++)
    {
        *(promovatiID + i) = f[i].id_promovat;
    }
    free(f);
    f = NULL;
    return promovatiID;
}
// afisam cati angajati au lucrat la un anumit proiect si media de performanta a proiectului;
void statisticaProiect(const angajat **firma, const size_t nr_angajati, const int index_proiect)
{
    int nrAngajatiPerProiect = 0;
    double medieProiect = 0;
    for (int i = 0; i < nr_angajati; i++)
    {
        const angajat *temp = firma[i];
        if (index_proiect <= temp->nr_proiecte)
        {
            nrAngajatiPerProiect++;
            medieProiect += temp->v_performanta[index_proiect];
        }
    }
    if (nrAngajatiPerProiect == 0)
    {
        printf("Niciun angajat nu a lucrat la acest proiect!\n");
    }
    else
    {
        medieProiect /= nrAngajatiPerProiect;
        printf("Numarul de angajati care au lucrat la proiect %d este %d\n", index_proiect + 1, nrAngajatiPerProiect);
        printf("Media de performanta a proiectului este %lf\n", medieProiect);
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
void *xcalloc(const size_t nr_elem, size_t size)
{
    void *v = calloc(nr_elem, size);
    if (v == NULL)
    {
        fprintf(stderr, "Eroare alocare\n");
        exit(EXIT_FAILURE);
    }
    return v;
}
void *xrealloc(void *v, const size_t size)
{
    void *p = realloc(v, size);
    if (p == NULL)
    {
        fprintf(stderr, "Eroare alocare\n");
        free(v);
        exit(EXIT_FAILURE);
    }
    v = p;
    return v;
}
int compare(const void *p1, const void *p2)
{
    const candidat *c1 = (const candidat *)p1;
    const candidat *c2 = (const candidat *)p2;
    if (c1->performanta_promovat == c2->performanta_promovat)
    {
        return 0;
    }
    return c1->performanta_promovat > c2->performanta_promovat ? -1 : +1;
}