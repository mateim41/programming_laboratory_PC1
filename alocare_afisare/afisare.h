#ifndef AFISARE_H
#define AFISARE_H

#include <stddef.h>

void afisare_int(void *v);
void afisare_real(void *v);
void afisare(void *v, size_t nr_elem, size_t elem_size, void (*afisare_elem)(void *const));

#endif