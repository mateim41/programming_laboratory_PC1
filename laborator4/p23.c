#include <stdio.h>
#include <stdlib.h>
#include "p23.h"

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);
    char op; // a p d
    scanf(" %c", &op);
    switch (op)
    {
    case 'a':
        while (x <= y)
        {
            if (tipnr(x) == 1)
                printf("%d\n", x);
            x++;
        }
        break;
    case 'p':
        while (x <= y)
        {
            if (tipnr(x) == 0)
                printf("%d\n", x);
            x++;
        }
        break;
    case 'd':
        while (x <= y)
        {
            if (tipnr(x) == -1)
                printf("%d\n", x);
            x++;
        }
        break;
    default:
        printf("Operatie gresita.\n");
        break;
    }

    return EXIT_SUCCESS;
}