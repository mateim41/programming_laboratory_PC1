#ifndef ANGAJATI2_H
#define ANGAJATI2_H

#include <stddef.h>

typedef struct
{
    int ID;
    int nr_proiecte;
    int *v_performanta;
} angajat;

void *xmalloc(const size_t size);
angajat *citireInformatii(const size_t nr_angajati);
void dealocareStruct(angajat **firma, const size_t nr_angajati);

// performanta medie a unui singur angajat
double scorMediuPerformanta(const angajat *firma, const size_t index_angajat);
int *angajatiPromovati(const angajat *firma, const size_t nr_angajati, const double prag_performanta, const size_t nr_min_proiecte, size_t *nrAngajatiPromovati);
void statisticaProiect(const angajat *firma, const size_t nr_angajati, const size_t index_proiect);

#endif