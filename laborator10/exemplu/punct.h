#ifndef TEST_H
#define TEST_H

struct _PUNCT
{
    double x, y;
};
typedef struct _PUNCT PUNCT;

double distanta(PUNCT a, PUNCT b);
PUNCT simetric(PUNCT a);
void afisare(PUNCT a);

#endif