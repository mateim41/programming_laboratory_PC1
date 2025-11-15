#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

unsigned int patrat(unsigned int n);
int main(void)
{
    clock_t start = clock();
    unsigned int x, y;
    printf("Primul numar din sir: ");
    scanf("%u", &x);
    while (x != 0)
    {
        y = patrat(x);
        printf("%u \n", y);
        scanf("%u", &x);
    }

    clock_t end = clock();
    double extime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %lfs\n", extime);
    return EXIT_SUCCESS;
}
unsigned int patrat(unsigned int n)
{
    unsigned int i, pp = 0;
    for (i = n; i > 0; i--)
    {
        if (sqrt(i) == (unsigned int)sqrt(i))
        {
            pp = i;
            break;
        }
    }

    return pp;
}
/*
    for (i = n; i > 0; i--)
    {
        unsigned int d;
        if (i == 1)
        {
            pp = i;
            break;
        }
        else
        {
            for (d = 1; d <= i / 2; d++)
            {
                if (d * d == i)
                {
                    pp = i;
                    break;
                }
            }
        }
        if (pp)
            break;
    }
    */