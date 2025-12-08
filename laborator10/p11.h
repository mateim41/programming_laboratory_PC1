#ifndef P1_H
#define P1_H

struct _fractie
{
    int x, y; // numarator si numitor
};
typedef struct _fractie fractie;

fractie inversa_fractie(fractie A);
fractie suma(fractie A, fractie B);
fractie produs(fractie A, fractie B);
void afisare(fractie A);

#endif