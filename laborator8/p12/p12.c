#include <stdio.h>
#include <stdlib.h>

#include "p12.h"

int main(void)
{
    size_t n, m; // n <- nr de niveluri, m <- apometre per coloana de apa
    printf("Numarul de etaje si numarul de apartamente: ");
    scanf("%zd %zd", &n, &m);
    printf("\n");

    printf("Consumul de apa al fiecarui apartament:\n");
    int bloc[NROW][NCOL];
    citireMatrice(bloc, n, m);
    printf("\n");

    int apometreSubsol[m];
    printf("Consumul citit pe apometrele de la subsol: ");
    citireVector(apometreSubsol, m);
    printf("\n");

    double pret_m3_apa;
    printf("Pretul unui m3 de apa: ");
    scanf("%lf", &pret_m3_apa);

    int consumApaColoana[m];
    for (int i = 0; i < m; i++)
    {
        consumApaColoana[i] = ConsumColoana(bloc, n, i);
    }

    int pierderi[m];
    for (int i = 0; i < m; i++)
    {
        pierderi[i] = apometreSubsol[i] - consumApaColoana[i];
    }
    printf("Pierderile pe fiecare coloana: ");
    afisareVector(pierderi, m);
    printf("\n");

    double redistrib[n][m];
    for (int j = 0; j < m; j++)
    {
        if (pierderi[j] == 0)
        {
            for (int i = 0; i < n; i++)
            {
                redistrib[i][j] = bloc[i][j];
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                redistrib[i][j] = redistribuire(bloc, i, j, consumApaColoana[j], pierderi[j]);
            }
        }
    }
    printf("Consumul dupa redistribuire:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%lf ", redistrib[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    double vectorPreturi[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vectorPreturi[i][j] = pret_m3_apa * redistrib[i][j];
        }
    }
    printf("Totalul de plata pentru fiecare apartament:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%lf ", vectorPreturi[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return EXIT_SUCCESS;
}