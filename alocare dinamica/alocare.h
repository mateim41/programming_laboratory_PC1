#ifndef ALOCARE_H
#define ALOCARE_H

#include <stddef.h>

void *xmalloc(size_t size);
void *xcalloc(size_t nrelem, size_t elem_size);
void *xrealloc(void *v, size_t size);

#endif