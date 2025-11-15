#include <stdio.h>
#include <stdlib.h>
#include "p12.h"
#include <time.h>

int main(void)
{
    clock_t start = clock();
    int a, b, c;
    printf("Introduceti 3 numere intregi: ");
    scanf("%d %d %d", &a, &b, &c);
    float meda = ma(a, b, c);
    float medg = mg(a, b, c);
    int min = Min(a, b, c);
    int max = Max(a, b, c);
    afisare(meda, medg, min, max);

    clock_t end = clock();
    double extime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time; %lfs\n", extime);
    return EXIT_SUCCESS;
}