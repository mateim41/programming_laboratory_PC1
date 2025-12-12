#include <stdio.h>
#include <stdlib.h>

#include "p13.h"

int main(void)
{
    data d;
    int tip_conversie;
    printf("Tipul de conversie pe care il facem: ");
    scanf("%d", &tip_conversie);
    switch (tip_conversie)
    {
        case 1:
        {
            printf("Tipul de conversie ales este 1. Cititi anul, luna si ziua din luna: ");
            scanf("%d %d %d", &d.an, &d.luna, &d.zi_luna);
            conversie1(&d);
            printf("Ziua din an este: %d\n", d.zi_an);
            break;
        }
        case 2:
        {
            printf("Tipul de conversie ales este 2. Cititi ziua din an si anul: ");
            scanf("%d %d", &d.zi_an, &d.an);
            conversie2(&d);
            printf("Luna este %d, iar ziua din luna este %d\n", d.luna, d.zi_luna);
            break;
        }
        default:
        {
            printf("Tip de conversie gresit.");
            break;
        }
    }

    return EXIT_SUCCESS;
}