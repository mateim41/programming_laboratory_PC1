#include <stdio.h>
#include <stdlib.h>
#include "p21.h"

int main(void)
{
    int n, x, y;
    printf("Introduceti numarul de perechi: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &x, &y);
        int d = cmmdc(x, y);
        if (prim(d))
            printf("Perechea (%d, %d) indeplineste conditia.\n", x, y);
    }

    return EXIT_SUCCESS;
}