#include <stdio.h>
#include <stdlib.h>

#include "p12_3.h"
#include "alocare_matrici.h"

#define bold "\033[1m"
#define reset "\033[0m"

int main(void)
{
    size_t n; // matrice patratica
    printf("Introduceti dimensiunea matricei: ");
    scanf("%zu", &n);
    if (n > 20)
    {
        fprintf(stderr, "Dimensiune depasita!\n");
        exit(EXIT_FAILURE);
    }
    printf("\nMatricea citita:\n");
    int **matrice = citireMatrice(n, n);
    printf("\n");
    char op;
    printf("Scrieti operatia pe care o efectuati:\n- Prima linie ordonata crescator: %sL%s\n", bold, reset);
    printf("- Prima coloana ordonata crescator: %sC%s\n- Diag principala ordonata crescator: %sD%s\n", bold, reset, bold, reset);
    scanf(" %c", &op);

    switch (op)
    {
    case 'L':
        primaLinieCresc(matrice, n, n);
        printf("Prelucrarea ai prima linie este ordonata cresc:\n");
        afisareMatrice((const int **)matrice, n, n);
        break;
    case 'C':
        primaColoanaCresc(matrice, n, n);
        printf("Prelucarea ai prima coloana este ordonata cresc:\n");
        afisareMatrice((const int **)matrice, n, n);
        break;
    case 'D':
        diagPrincCresc(matrice, n, n);
        printf("Prelucarea ai diagonala principala este ordonata cresc:\n");
        afisareMatrice((const int **)matrice, n, n);
        break;
    default:
        printf("Operatie gresita!\n");
        break;
    }

    dealocareMatrice((void ***)&matrice, n);
    return EXIT_SUCCESS;
}