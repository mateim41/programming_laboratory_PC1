#include <stdio.h>

#include "p11.h"

int cmmdc(int a, int b);
fractie reducere_fractie(fractie A);

fractie inversa_fractie(fractie A)
{
    fractie b;
    b.x = A.y;
    b.y = A.x;
    return b;
}
fractie suma(fractie A, fractie B)
{
    /*
    1   -2
    3    3
    */
    fractie S;
    S.x = A.x * B.y + A.y * B.x;
    S.y = A.y * B.y;
    S = reducere_fractie(S);
    return S;
}
fractie produs(fractie A, fractie B)
{
    fractie P;
    P.x = A.x * B.x;
    P.y = A.y * B.y;
    P = reducere_fractie(P);
    return P;
}
fractie reducere_fractie(fractie A)
{
    int div_comun = cmmdc(A.x, A.y);
    A.x /= div_comun;
    A.y /= div_comun;
    return A;
}

int cmmdc(int a, int b)
{
    if (a < 0)
        a = -a;
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void afisare(fractie A)
{
    if (A.y != 1)
        printf("%d/%d\n", A.x, A.y);
    else
        printf("%d\n", A.x);
}