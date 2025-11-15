#include <stdio.h>
#include <stdlib.h>
#include "vectorreal.h"

int main(void)
{
    int n; // nr de elem
    printf("Numarul de date experimentale: ");
    scanf("%d", &n);
    double x[n];
    printf("Introduceti datele experimentale: ");
    citire(x, n);
    double med = 0;
    avgreal(x, &med, n); // valoarea medie a sirului x
    printf("Valoarea medie a sirului x este: %lf\n", med);
    double ea = abatere(x, n); // abaterea medie patratica
    printf("Abaterea medie patratica este: %lf\n", ea);
    nrelem(x, n);
    double y[n];
    int cnt = vector(x, y, n);//vector cu valorile mai mari ca val med
    afisare(y, n - 1 - cnt);

    return EXIT_SUCCESS;
}