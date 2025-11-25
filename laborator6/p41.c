#include <stdio.h>
#include <stdlib.h>
#include "fct.h"

int main(void)
{
    int n;            // nr total de comori
    int t;            // nr de comori cu capcane
    int comori[100];  // contine numarul de monede din fiecare comoara
    int capcane[100]; // contine indicii pe care se afla comorile cu capcane
    printf("Numarul de comori este: ");
    scanf("%d", &n);
    printf("Numarul de comori cu capcane este: ");
    scanf("%d", &t);
    citire(comori, n);
    citire(capcane, t);
    unsigned int s = suma(comori, capcane, n, t);
    printf("%u\n", s);

    return EXIT_SUCCESS;
}