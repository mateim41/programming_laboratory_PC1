#ifndef ANGAJATI3_H
#define ANGAJATI3_H

#include <stddef.h>
typedef struct
{
    int ID;
    int nr_proiecte;
    int *v_performanta;
} angajat;

void *xmalloc(const size_t size);
angajat *citireAngajat();
angajat **citireFirma(const size_t nr_angajati);
void dealocare(angajat ***firma, const size_t nr_angajati);

double scorMediuPerformanta(const angajat **firma, const size_t index_angajat);
int *angajatiPromovati(const angajat **firma, const size_t nr_angajati, const double prag_performanta, const int nr_min_proiecte, size_t *nrPromovati);
// afisam cati angajati au lucrat la un anumit proiect si media de performanta a proiectului;
void statisticaProiect(const angajat **firma, const size_t nr_angajati, const int index_proiect);

#endif