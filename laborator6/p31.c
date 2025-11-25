#include <stdio.h>
#include <stdlib.h>

void interschimb(int *a, int *b);
int main(void)
{
    int a = 0;
    int b = 0;
    printf("Introduceti cele doua numere: ");
    scanf("%d %d", &a, &b);
    interschimb(&a, &b);
    printf("%d %d\n", a, b);

    return EXIT_SUCCESS;
}
void interschimb(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}