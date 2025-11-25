#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "p11.h"
#include "alocare.h"

int main(void)
{
    printf("Introduceti numarul de zile: ");
    int n;
    scanf("%d", &n);

    printf("Introduceti temperaturile minime: ");
    int *tempMin = pcitireVector2(n);

    printf("Introduceti temperaturile maxime: ");
    int *tempMax = pcitireVector2(n);

    // calculam media fiecarei zile
    printf("Valorile medii sunt: ");
    double *tempMed = vectorMedie(tempMin, tempMax, n);
    pafisareVectorReali(tempMed, n);

    // calculam media tuturor temperaturilor
    printf("Valoarea medie este: ");
    double m = mediaAritmeticaVector(tempMed, n);
    printf("%lf\n", m);

    // eliberam memoria
    memset(tempMin, 0, n);
    memset(tempMax, 0, n);
    memset(tempMed, 0, n);

    free(tempMin);
    free(tempMax);
    free(tempMed);

    tempMin = nullptr;
    tempMax = nullptr;
    tempMed = nullptr;

    return EXIT_SUCCESS;
}