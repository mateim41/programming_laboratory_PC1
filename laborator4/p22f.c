#include <stdio.h>
#include <math.h>
#include "p22.h"

int sdiv(int a)
{
    int s = 1;
    int l = (int)sqrt(a);
    for (int d = 2; d <= l; d++)
        if (a % d == 0)
            s = s + d + a / d;
    return s;
}
int prietene(int x, int y)
{
    if (sdiv(x) == y && sdiv(y) == x)
        return 1;
    return 0;
}