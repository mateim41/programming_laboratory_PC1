#ifndef P13_H
#define P13_H

#include <stddef.h>

struct DATA
{
    int an;
    int zi_an;
    int luna;
    int zi_luna;
};
typedef struct DATA data;

void *xmalloc(const size_t size);
void conversie1(data *d);
void conversie2(data *d);

#endif