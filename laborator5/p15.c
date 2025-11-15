#include <stdio.h>
#include <stdlib.h>
#include "vectorint.h"

int main(void)
{
    int n; // max 30 elemente
    printf("Numarul de elemente ale vectorului: ");
    scanf("%d", &n);
    int v[30];
    printf("Elementele vectorului: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    ordonareBule(v, n);//ordonam valorile in ord cresc
    printf("Elementele ordonate: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
        if (i == n - 1)
            printf("\n");
    }

    return EXIT_SUCCESS;
}