#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

bool tris(int a, int b, int c);
bool trech(int a, int b, int c);
bool trdr(int a, int b, int c);
bool trscalen(int a, int b, int c);
int main(void)
{
    clock_t start = clock();
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (tris(a, b, c) && trech(a, b, c) == 0)
        printf("Triunghiul este isoscel\n");
    else if (trech(a, b, c))
        printf("Triunghiul este echilateral\n");
    else if (trdr(a, b, c))
        printf("Triunghiul este dreptunghic\n");
    else if (trscalen(a, b, c))
        printf("Triunghiul este scalen\n");
    else
        printf("Nu este triunghi\n");

    clock_t end = clock();
    double extime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %lfs\n", extime);
    return EXIT_SUCCESS;
}
bool tris(int a, int b, int c)
{
    if (a == b || a == c || b == c)
        return true;
    else
        return false;
}
bool trech(int a, int b, int c)
{
    if (a == b && a == c)
        return true;
    else
        return false;
}
bool trdr(int a, int b, int c)
{
    if (a * a + b * b == c * c)
        return true;
    else if (a * a + c * c == b * b)
        return true;
    else if (b * b + c * c == a * a)
        return true;
    else
        return false;
}
bool trscalen(int a, int b, int c)
{
    if (a > 0 && b > 0 && c > 0)
    {
        if (a + b > c || a + c > b || b + c > a)
            return true;
        else
            return false;
    }
    else
        return false;
}