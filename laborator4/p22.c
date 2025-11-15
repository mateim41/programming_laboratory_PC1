#include <stdio.h>
#include <stdlib.h>
#include "p22.h"
#include <time.h>

int main(void)
{
    clock_t start = clock();
    int x, y; // 10 1000
    scanf("%d %d", &x, &y);
    while (x <= y)
    {
        int fr = sdiv(x);
        if (fr > x && fr <= y && sdiv(fr) == x)
            printf("%d %d\n", x, fr);
        x++;
    }

    clock_t end = clock();
    double extime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %lfs\n", extime);
    return EXIT_SUCCESS;
}