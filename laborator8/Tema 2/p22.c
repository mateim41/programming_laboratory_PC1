#include <stdio.h>
#include <stdlib.h>

#include "tema2.h"

int main(void)
{
    size_t n, m;
    // n - dimensiunea matricii patratice A
    // m - dimensiunea matricii patratice B
    printf("Introduceti dimensiunile celor doua matrici: ");
    scanf("%zd %zd", &n, &m);

    int A[NROW][NCOL], B[NROW][NCOL];
    printf("Cititi cele doua matrici:\n");
    citireMatrice(A, n, n);
    printf("\n");
    citireMatrice(B, m, m);
    printf("\n");

    int AT[NCOL][NROW] = {0}, BT[NCOL][NROW] = {0};
    transpusaMatrice(AT, A, n, n);
    transpusaMatrice(BT, B, m, m);

    printf("Matricea A transpusa:\n");
    afisareMatrice(AT, n, n);
    printf("\n");
    printf("Matricea B transpusa:\n");
    afisareMatrice(BT, m, m);
    printf("\n");

    // verificam proprietatea
    int P[NROW][NCOL] = {0}; // (A * B)
    produsMatrici(P, A, n, n, B, m, m);
    int PT[NROW][NCOL] = {0}; // P transpus
    transpusaMatrice(PT, P, n, m);

    int produsTranspus[NROW][NCOL] = {0}; // BT * AT
    produsMatrici(produsTranspus, BT, m, m, AT, n, n);

    printf("Produsul (A*B)^T:\n");
    afisareMatrice(PT, n, m);
    printf("\n");
    printf("Produsul BT * AT:\n");
    afisareMatrice(produsTranspus, m, n);

    return EXIT_SUCCESS;
}