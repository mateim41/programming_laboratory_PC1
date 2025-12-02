#include <stdio.h>
#include <stdlib.h>

#include "tema2.h"

int main(int argc, char const *argv[])
{
    size_t n;
    printf("Dimensiunea matricei patratice: ");
    scanf("%zd", &n);
    printf("\n");

    printf("Matricea citita:\n");
    int **A = citireMatrice_dinamic(n, n);
    printf("\n");

    printf("Transpusa matricei:");
    int **AT = (int **)alocareMatrice(n, n, sizeof(int));
    printf("\n");
    transpusaMatrice_dinamic(AT, A, n, n);
    afisareMatrice_dinamic(AT, n, n);
    int **I = matrice_unitate(n, n);

    int **P = produsMatrice_dinamic(A, n, n, AT, n, n);
    if (P != NULL)
    {
        printf("Produsul celor doua matrici:\n");
        afisareMatrice_dinamic(P, n, n);

        printf("Matricea unitate:\n");
        afisareMatrice_dinamic(I, n, n);

        int ok = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (P[i][j] != I[i][j])
                {
                    ok = 0;
                    break;
                }
            }
            if (ok == 0)
            {
                break;
            }
        }
        if (ok == 1)
        {
            printf("Matricea A este ortogonala(A * AT = In).\n");
        }
        else
        {
            printf("Matricea A nu este ortogonala(A * AT != In).\n");
        }
    }
    dealocareMatrice((void ***)&A);
    dealocareMatrice((void ***)&AT);
    dealocareMatrice((void ***)&I);
    dealocareMatrice((void ***)&P);

    return EXIT_SUCCESS;
}