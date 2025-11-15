#include <stdio.h>
#include <stdlib.h>
#include "vectorreal.h"

int main(void)
{
    int n;
    printf("Numarul de masuratori facute: ");
    scanf("%d", &n);
    double x[n];       // sirul cu valorile concentratiilor la momentele de timp
    double t[n];       // sirul cu valorile momentelor de timp
    double unitate[n]; // vector care nu influenteaza functia prodscalar
    for (int i = 0; i < n; i++)
    {
        unitate[i] = 0;
    }
    printf("Introduceti cele doua siruri: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &t[i]);
    }
    double A[2][3], X[2][1];
    // initializam matricea sistemului
    X[1][0] = 0;
    X[2][0] = 0;

    A[0][0] = n;
    A[0][1] = prodscalar(t, unitate, n);
    A[0][2] = prodscalar(x, unitate, n);
    A[1][0] = A[0][1];
    A[1][1] = prodscalar(t, t, n);
    A[1][2] = prodscalar(t, x, n);

    double a = 0, b = 0; // coeficientii ecuatiei

    if (rezsistem(A, X) == 3)
    {
        printf("Nu se pot calcula coeficientii a si b.\n");
    }
    else
    {
        double detA = A[0][0] * A[1][1] - A[0][1] * A[1][0];
        if (rezsistem(A, X) == 1)
        {
            double da = (A[0][2] * A[1][1] - A[0][1] * A[1][2]) / detA;
            double db = (A[0][0] * A[1][2] - A[0][2] * A[1][0]) / detA;
            printf("Ecuatia este x = %lf * t + %lf\n", da, db);
        }
        else
        {
            // SCN => nec princ, nec sec: b=alfa si a e in fct de alfa
            printf("Sistem compatibil nedeterminat => a/b este in functie de alfa.\n");
        }
    }

    return EXIT_SUCCESS;
}