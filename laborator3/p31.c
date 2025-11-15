#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void)
{
    clock_t begin = clock();
    float x, y;
    int c, c1 = 0;
    printf("Coordonatele punctului sunt: ");
    scanf("%f %f", &x, &y);
    if (y > 0)
    {
        if (x > 0)
        {
            c = 1;
        }
        else if (x < 0)
        {
            c = 2;
        }
        else
        {
            c = 1;
            c1 = 2;
        }
    }
    else if (y < 0)
    {
        if (x > 0)
        {
            c = 4;
        }
        else if (x < 0)
        {
            c = 3;
        }
        else
        {
            c = 3;
            c1 = 4;
        }
    }
    else
    {
        if (x > 0)
        {
            c = 1;
            c1 = 4;
        }
        else if (x < 0)
        {
            c = 2;
            c1 = 3;
        }
        else
        {
            c = 0;
        }
    }
    if (c == 0)
        printf("Centrul axelor de coordonate\n");
    else if (c1 == 0)
        printf("Punctul se afla in cadranul %d\n", c);
    else
        printf("Punctul se afla intre cadranele %d-%d\n", c, c1);

    clock_t end = clock();
    double extime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution time: %lfs\n", extime);
    return EXIT_SUCCESS;
}