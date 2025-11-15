#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define RED "\e[0;31m"
#define BLUE "\e[0;34m"
#define YEL "\e[;33m"
#define RESET "\e[0m"

int main(void)
{
    clock_t start = clock();
    float b, x, y;
    unsigned int poz;
    scanf("%f", &b); // 2.2
    printf("Prima valoare din sir este: ");
    scanf("%f", &x); // 11.75
    poz = 1;
    float a = fabs(b - x); // 9.55
    y = a;
    unsigned int pozmax = 1;
    while (x >= 0)
    {
        if (fabs(b - x) < a)
        {
            a = fabs(b - x);
            y = x;
            pozmax = poz;
        }
        scanf("%f", &x);
        poz++;
    }
    printf("%sCea mai apropiata%s %svaloare de b%s %seste %f de pe pozitia %d%s\n", RED, RESET, BLUE, RESET, YEL, y, pozmax, RESET);

    clock_t end = clock();
    double extime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %lfs\n", extime);
    return EXIT_SUCCESS;
}