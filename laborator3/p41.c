#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// sdiv > x abundent
// sdiv == x perfect
// sdiv < x deficient
unsigned int sdiv(unsigned int x);
int main(void)
{
    clock_t begin = clock();
    unsigned int x, y;
    printf("Intervalul este: ");
    scanf("%u %u", &x, &y);
    char op;
    printf("Tipul de numar cautat(a, p, d): ");
    scanf("%s", &op);
    switch (op)
    {
    case 'a':
        printf("Numerele abundente sunt:\n");
        while (x <= y)
        {
            unsigned int s = sdiv(x);
            if (s > x)
                printf("%u\n", x);
            x++;
        }
        break;
    case 'p':
        printf("Numerele perfecte sunt:\n");
        while (x <= y)
        {
            unsigned int s = sdiv(x);
            if (s == x)
                printf("%u\n", x);
            x++;
        }
        break;
    case 'd':
        printf("Numerele deficiente sunt:\n");
        while (x <= y)
        {
            unsigned int s = sdiv(x);
            if (s < x)
                printf("%u\n", x);
            x++;
        }
        break;
    default:
        printf("Operatie gresita.\n");
        break;
    }

    clock_t end = clock();
    double extime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution time: %lfs\n", extime);
    return EXIT_SUCCESS;
}
unsigned int sdiv(unsigned int x)
{
    unsigned int sdiv = 1;
    for (unsigned int d = 2; d <= x / 2; d++)
        if (x % d == 0)
            sdiv += d;
    return sdiv;
}