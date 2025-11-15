#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double x, y;
    printf("Introduceti x: ");
    scanf("%lf", &x);
    if (x <= 2)
    {
        y = x * x + 3 * x + 5;
    }
    else if (x < 8)
    {
        y = 3 * x;
    }
    else
    {
        y = exp(x) + 2;
    }
    printf("Valoarea functiei este %.5lf\n", y);

    return EXIT_SUCCESS;
}