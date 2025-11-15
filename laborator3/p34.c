#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int sdiv(int a);
int main(void)
{
    clock_t start = clock();
    unsigned long int a, b;
    printf("Intervalul este:");
    scanf("%lu %lu", &a, &b);
    while (a < b)
    {
        unsigned int s = sdiv(a); // suma div pt a
        for (unsigned long int i = a + 1; i <= b; i++)
        {
            if (s == i && sdiv(i) == a)
            {
                printf("%lu %lu\n", a, i);
            }
        }
        a++;
    }

    clock_t end = clock();
    double extime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %lfs\n", extime);
    return EXIT_SUCCESS;
}
unsigned int sdiv(int a)
{
    unsigned int sdiv = 1;
    for (unsigned int d = 2; d <= a / 2; d++)
        if (a % d == 0)
            sdiv += d;
    return sdiv;
}