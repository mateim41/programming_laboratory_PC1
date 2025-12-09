#include <stdio.h>
#include <stdlib.h>

#include "p12_3.h"
#include "alocare_matrici.h"

#define bold "\033[1m"
#define reset "\033[0m"

int main(void)
{
    size_t n, m;
    printf("Introduceti dimensiunile matricei: ");
    scanf("%zd %zd", &n, &m);
    printf("\n");
    if (n != m)
    {
        fprintf(stderr, "Nu au sens operatiile\n");
        exit(EXIT_FAILURE);
    }
    printf("Cititi matricea:\n");
    int **matrice = citireMatrice(n, m);

    char op; // D S M
    printf("\nIntroduceti operatia pe care o doriti:\n- Diagonala principala ordonata crescator: %sD%s\n", bold, reset);
    printf("- Diagonala secundara ordonata crescator: %sS%s\n- Linia mediana ordonata crescator: %sM%s\n", bold, reset, bold, reset);
    scanf(" %c", &op);

    switch (op)
    {
    case 'D':
    {
        diagPrincCresc(matrice, n, m);
        printf("Prelucrarea ai diagonala principala este ordonata crescator:\n");
        afisareMatrice((const int **)matrice, n, m);
        break;
    }
    case 'S':
    {
        diagSecCresc(matrice, n, m);
        printf("Prelucrarea ai diagonala secundara este ordonata crescator:\n");
        afisareMatrice((const int **)matrice, n, m);
        break;
    }
    case 'M':
    {
        if (m % 2 != 1)
        {
            printf("Numarul de coloane nu este impar.\n");
            break;
        }
        LiniaMedianaVerticala(matrice, n, m);
        printf("Prelucrarea ai linia mediana verticala este ordonata crescator:\n");
        afisareMatrice((const int **)matrice, n, m);
        break;
    }
    default:
    {
        printf("Operatie gresita!\n");
        break;
    }
    }

    dealocareMatrice((void ***)&matrice, n);
    return EXIT_SUCCESS;
}