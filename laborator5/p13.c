#include <stdio.h>
#include <stdlib.h>
#include "vectorint.h"

int main(int argc, char *argv[])
{
    int tempmin[31]; // temp minima la 5
    int tempmax[31]; // temp maxima la 17
    int n;
    printf("Numarul de zile analizate: ");
    scanf("%d", &n);
    printf("Temperaturile minime: ");
    citire(tempmin, n);
    printf("Temperaturile maxime: ");
    citire(tempmax, n);
    // determinam temp medie a fiecarei zile
    double vmed[31];
    for (int i = 0; i < n; i++)
    {
        vmed[i] = 0;
        vmed[i] = (tempmin[i] + tempmax[i]) / 2.0;
    }
    // determinam temp maxime si minime
    int min = 0, max = 0;
    max = vmax(tempmax, n);
    min = vmin(tempmin, n);
    double ma = 0;
    // determinam valoarea medie a temp medii
    for (int i = 0; i < n; i++)
    {
        ma += vmed[i];
    }
    ma /= (double)n;
    // avgreal(vmed, &ma, n);
    // facem media geometrica a valorilor maxime
    double mg = 0;
    medgeom(tempmax, &mg, n);
    // afisare
    printf("Valorile medii din fiecare zi sunt: ");
    for (int i = 0; i < n; i++)
        printf("%f ", vmed[i]);
    printf("\n");
    printf("Valoarea maxima a temp este: %d\n", max);
    printf("Valoarea minima a temp este: %d\n", min);
    printf("Valoarea medie a temp medii este: %lf\n", ma);
    printf("Media geometrica a valorilor maxime este: %lf\n", mg);

    return EXIT_SUCCESS;
}