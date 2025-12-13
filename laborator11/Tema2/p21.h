#ifndef P21_H
#define P21_H

#include <stddef.h>
struct rVector
{
    char *nume; // numele vectorului
    size_t nr_elemente;
    double *vector;
}; // vector cu elemente reale
typedef struct rVector vectorReal;

vectorReal *citireVector();
void afisare(vectorReal *vec);
void ordonareCrescValoare(vectorReal *vec);
void ordonareCrescSumaCifModul(vectorReal *vec);
void prelucrareVector(vectorReal *vec, const char *operatie);
void dealocareStruct(vectorReal **vec);

#endif