#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *pInt = 0, *pInt1 = 0, *pInt2 = 0;
    double b[10] = {0};
    double *pDouble = 0, *pDouble1 = 0, *pDouble2 = 0;

    size_t dimI, dimD;

    pInt = a;
    pInt1 = &a[0];

    pDouble = b;
    pDouble1 = &b[0];

    printf("Valoarea lui a este: %p\n", a);
    printf("Valoarea lui pInt este: %p\n", pInt);
    printf("Valoarea lui pInt1 este: %p\n", pInt1);

    printf("\n");

    printf("Valoarea lui b este: %p\n", b);
    printf("Valoarea lui pDouble este: %p\n", pDouble);
    printf("Valoarea lui pDouble1 este: %p\n", pDouble1);

    printf("\n");

    dimI = sizeof(int);
    dimD = sizeof(double);

    pInt2 = a + 1;
    b[2] = a[2] * 3.14159;
    pDouble2 = b + 2;

    printf("Valoarea lui pInt2 este: %p\n", pInt2);
    printf("Valoarea lui pDouble2 este: %p\n", pDouble2);

    printf("\n");

    printf("Valoarea lui pInt2 este: %d\n", *pInt2);
    printf("Valoarea lui pDouble2 este: %lf\n", *pDouble2);

    printf("\n");

    // a = a + 1;
    // b = b + 2;

    pInt1 = pInt1 + 1;
    printf("Valoarea de la adresa lui pInt1 este: %d\n", *pInt1);
    printf("Adresa lui pInt1 este: %p\n", pInt1);
    printf("Valoarea de la adresa lui a este: %d\n", *a);
    printf("Valoarea de la adresa lui a + 1 este: %d\n", *(a + 1));
    printf("Valoarea elementului a[0] este: %d\n", a[0]);
    printf("Valoarea elementului a[1] este: %d\n", a[1]);
    printf("Valoarea elementului pInt1[0] este: %d\n", pInt1[0]);

    return EXIT_SUCCESS;
}
// 2.1: Observam ca valoarea lui a, pInt, pInt1 este aceeasi. Ambele pointeaza catre aceeasi adresa

// 2.2: b, pDouble, pDouble 1 - aceeasi valoare(adresa)

// 2.3: adresa lui pInt2 si pDouble2 difera doar printr-o cifra de valoarea lui a si a lui b

// 2.4: apar erori de assignment; dat fiind ca a si b sunt vectori care contin mai multe valori nu pot sa fac operatii aritmetice cu vectorul per intreg

// 2.5: dat fiind ca array decays to pointer, putem lucra cu vectorul a ca si cu un pointer, fara []; la fel si cu pInt1, acesta ia adresa primului element din a, iar cand fac pInt1 = pInt1 + 1; practic modific indexul de la care porneste vectorul pInt1