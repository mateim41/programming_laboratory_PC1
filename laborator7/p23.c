#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "p223.h"
#include "alocare.h"

int main(void)
{
    long int x;
    printf("Introduceti numarul: ");
    scanf("%ld", &x);
    size_t n = 0;
    char *sir = transformareToASCII(x, &n);
    printf("%s\n", sir);
    printf("\n");
    free(sir);
    sir = nullptr;

    return EXIT_SUCCESS;
}