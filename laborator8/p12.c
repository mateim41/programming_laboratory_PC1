#include <stdio.h>
#include <stdlib.h>

#include "p12.h"

int main(void)
{
    int b[NROW][NCOL];
    size_t n, m;
    printf("Introduceti dimensiunea matricei: ");
    scanf("%zd %zd", &n, &m);
    citireMat(b, n, m);

    int apasubsol[m];
    printf("Valoarea apometrului de la subsol: ");
    citireVec(apasubsol, m);
    int apacoloana[m];
    for (int i = 0; i < m; i++)
    {
        apacoloana[i] = sumacol(b, n, i);
    }
    int fpierd[m];
    for (int i = 0; i < n; i++)
    {
        fpierd[i] = pierderi(apacoloana, i, apasubsol[i]);
    }

    double redistrib[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (fpierd[j])
            {
                redistrib[i][j] = redistribuire(b, i, j, fpierd[j], apacoloana[j]);
            }
            else
            {
                redistrib[i][j] = b[i][j];
            }
        }
    }
    afisareMat(b, n, m);
    afisareVec(apasubsol, m);
    afisareVec(apacoloana, m);
    afisareVec(fpierd, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%lf ", redistrib[i][j]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}