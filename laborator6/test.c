#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int v[5] = {1, 2, 3, 4, 5};
    int *pv = v;
    int **pqv = &pv;
    printf("Adresa lui pv este: %d\n", *pv);
    printf("Adresa lui pqv este: %d\n", **pqv);

    return EXIT_SUCCESS;
}