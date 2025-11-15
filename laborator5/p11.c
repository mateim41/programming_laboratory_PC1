#include <stdio.h>
#include <stdlib.h>
#include "vectorint.h"

int main(void)
{
    int n;
    printf("Introduceti dimensiunea vectorilor: ");
    scanf("%d", &n);
    int StocDeal[n];
    int StocVale[n];
    int prettotal[n];
    int preturi[n];
    int Suma[n];
    printf("Introduceti stoc deal: ");
    citire(StocDeal, n);
    printf("Introduceti stoc vale: ");
    citire(StocVale, n);
    printf("Introduceti pretul fiecarui tip: ");
    citire(preturi, n);
    // suma este nr de produse din fiecare tip
    suma(StocDeal, StocVale, Suma, n);
    // produsul este valoarea totala a produselor de fiecare tip
    produs(Suma, preturi, prettotal, n);
    printf("Numarul total de produse din fiecare tip este: ");
    afisare(Suma, n);
    printf("Pretul total al fiecarui produs este: ");
    afisare(prettotal, n);  

    return EXIT_SUCCESS;
}