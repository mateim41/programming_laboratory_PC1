#ifndef ALOCARE_H
#define ALOCARE_H

#include <stddef.h>

void *xmalloc(size_t size);
void *xcalloc(size_t nr_elem, size_t size);
void *xrealloc(void *v, size_t size);
// free(v)

#endif