#include <stdio.h>
#include <stdlib.h>

void afisare(int *p, int n);

int main(void)
{
    /*
    int a = 42;
    int *p = &a; // <- declaratie (* = parte din tipul variabilei)
    printf("*p este = %d\n", *p);// <- utilizare (* = operatorul de dereferentiere)

    // & = operator de referentiere ("address-of")
    // * = operator de dereferentiere ("valoarea de la adresa")
    */
    int v[6] = {[2] = 1, 2, 3, [1] = 4}; // cand nu dau toate elementele intre acolade restul elem vor fi 0
    int r = 2;                           // nr de linii
    int c = 3;                           // nr de coloane
    int n = sizeof(v) / sizeof(v[0]);
    // sizeof(v) = 20 (5 * sizeof(int))
    // sizeof(v[0]) = 4 (sizeof(int))

    // int *l0 = v;
    // int *l1 = v + 3;

    int *p = v;
    afisare(v + 1, n - 1);
    afisare(p, n);
    printf("\n");

    // afisam ca matrice
    for (int i = 0; i < r; i++)
    {
        afisare(v + i * c, c);
    }

    printf("\n Afisare alternativa:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);

        if ((i + 1) % c == 0)
        {
            printf("\n");
        }
    }

    printf("\nAfisare alternativa 2:\n");
    for (int *p = v; p < v + n; p += c)
    {
        afisare(p, c);
    }

    return EXIT_SUCCESS;
}
void afisare(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");
}