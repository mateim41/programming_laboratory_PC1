#include <stdio.h>
#include <stdlib.h>

#include "p223.h"
#include "alocare.h"

int main(void)
{
    printf("Cardinalul multimii A: ");
    size_t n;
    scanf("%ld", &n);
    printf("Cardinalul multimii B: ");
    size_t m;
    scanf("%ld", &m);

    double *A = Citire(n);
    double *B = Citire(m);

    char op; // operatie I, R, DS
    printf("Introduceti operatia: ");
    scanf(" %c", &op);
    switch (op)
    {
    case 'I':
        size_t card1 = 0;
        double *I = (double *)Intersectie(A, B, n, m, &card1);
        Afisare(I, card1);
        free(I);
        I = nullptr;
        break;
    case 'R':
        size_t card2 = 0;
        double *R = (double *)Reuniune(A, B, n, m, &card2);
        Afisare(R, card2);
        free(R);
        R = nullptr;
        break;
    case 'D':
        size_t card3 = 0;
        double *DS = (double *)DiferentaSimetrica(A, B, n, m, &card3);
        Afisare(DS, card3);
        free(DS);
        DS = nullptr;
        break;
    default:
        printf("Operatie gresita!\n");
        break;
    }

    free(A);
    free(B);
    A = nullptr;
    B = nullptr;

    return EXIT_SUCCESS;
}