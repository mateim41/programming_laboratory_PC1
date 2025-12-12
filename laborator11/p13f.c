#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "p13.h"

#pragma region luniAN
int vectorLuni[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool esteBisect(int an)
{
    if ((an % 4 == 0 && an % 100 != 0) || an % 400 == 0)
        return true;
    return false;
}
void modifLunaBisect(int an, int *vectorLuni)
{
    if (esteBisect(an))
        vectorLuni[2] = 29;
    else
        vectorLuni[2] = 28;
}
#pragma endregion

void *xmalloc(const size_t size);
// citim ziua din luna, luna si anul si gasim __ziua din an__
void conversie1(data *d)
{
    modifLunaBisect(d->an, vectorLuni);
    int ziAN = 0;
    for (int i = 1; i < d->luna; i++)
    {
        ziAN += *(vectorLuni + i);
    }
    ziAN += d->zi_luna;
    d->zi_an = ziAN;
}
// citim ziua din an si anul
void conversie2(data *d)
{
    modifLunaBisect(d->an, vectorLuni);
    int l = 0, z = 0;
    for (int i = 1; i <= 12; i++)
    {
        z += *(vectorLuni + i);
        if (z > d->zi_an)
        {
            z -= *(vectorLuni + i);
            l = i;
            break;
        }
    }
    int cz = d->zi_an - z;
    if (cz == 0 && esteBisect(d->an) == false)
        d->zi_luna = 1;
    else if (cz == 0 && esteBisect(d->an) == true && l == 3)
    {
        d->zi_luna = 29;
        if (l == 3)
            l -= 1;
    }
    else
        d->zi_luna = cz;
    d->luna = l;
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