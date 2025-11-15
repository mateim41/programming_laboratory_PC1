#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

unsigned int cmmdc(unsigned int a, unsigned int b);
int main(void)
{
    clock_t start = clock();
    unsigned int x, y, d;
    printf("Introduceti cele doua numere: ");
    scanf("%u %u", &x, &y);
    d = cmmdc(x, y);
    printf("Cmmdc al celor doua numere este %u\n", d);

    clock_t end = clock();
    double extime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %lfs\n", extime);
    return EXIT_SUCCESS;
}
unsigned int cmmdc(unsigned int a, unsigned int b)
{
    unsigned int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}