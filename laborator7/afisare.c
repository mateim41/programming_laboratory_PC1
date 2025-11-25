#include <stdio.h>
#include <stdlib.h>

#include "afisare.h"

void afisare_int(void *v)
{
    printf("%d ", *(int *)v);
}
void afisare_real(void *v)
{
    printf("%lf ", *(double *)v);
}
void afisare_real3(void *v)
{
    printf("%.3lf ", *(double *)v);
}
void afisare(void *v, size_t nr_elements, size_t elem_size, void (*afisare_elem)(void *const))
{
    char *p = (char *)v;
    for (int i = 0; i < nr_elements; i++)
    {
        afisare_elem(p);
        p += elem_size;
    }
    printf("\n");
}