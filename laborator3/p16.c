#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float x, p = 1;
    scanf("%f", &x);
    while (x != 0)
    {
        p *= x;
        scanf("%f", &x);
    }
    printf("%.2f\n", p);

    return EXIT_SUCCESS;
}