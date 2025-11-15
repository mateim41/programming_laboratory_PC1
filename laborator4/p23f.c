#include <stdio.h>
#include "p23.h"

int sdiv(int a)
{
    int s = 1;
    for (int d = 2; d <= a / 2; d++)
        if (a % d == 0)
            s += d;
    return s;
}
int tipnr(int x)
{
    if (sdiv(x) < x)
        return -1;
    else if (sdiv(x) == x)
        return 0;
    return 1;
}