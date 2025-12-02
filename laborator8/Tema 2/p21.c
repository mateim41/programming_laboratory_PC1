#include <stdio.h>
#include <stdlib.h>

#include "tema2.h"

int main(void)
{
    size_t n, m, p, q;
    // n - nr linii A
    // m - nr coloane A
    // p - nr linii B
    // q - nr coloane B
    printf("Introduceti dimensiunile matricilor: ");
    scanf("%zd %zd %zd %zd", &n, &m, &p, &q);

    int A[NROW][NCOL], B[NROW][NCOL];
    printf("Cititi cele doua matrici:\n");
    citireMatrice(A, n, m);
    printf("\n");
    citireMatrice(B, p, q);
    printf("\n");

    char op; // S / P - suma / produs
    scanf(" %c", &op);
    switch (op)
    {
    case 'S':
    {
        int S[NROW][NCOL] = {0};
        sumaMatrici(S, A, n, m, B, p, q);
        afisareMatrice(S, n, m);
        break;
    }
    case 'P':
    {
        int P[NROW][NCOL] = {0};
        produsMatrici(P, A, n, m, B, p, q);
        afisareMatrice(P, n, q);
        break;
    }
    default:
        printf("Operatie gresita!\n");
        break;
    }

    return EXIT_SUCCESS;
}