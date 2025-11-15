#include <stdio.h>
#include "p21.h"

int cmmdc(int x, int y)
{
    while (y)
    {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}
int prim(int a)
{
    if (a < 2)
        return 0;
    else
    {
        for (int d = 2; d <= a / 2; d++)
            if (a % d == 0)
                return 0;
    }
    return 1;
}