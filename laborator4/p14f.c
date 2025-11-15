#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "p14.h"

_Bool verif(int a, int b, int c)
{
    if (a < 0 || b < 0 || c < 0)
        return false;
    if (a + b > c || a + c > b || b + c > a)
        return true;
    else
        return false;
}
_Bool trech(int a, int b, int c)
{
    if (a == b && a == c)
        return true;
    else
        return false;
}
_Bool tris(int a, int b, int c)
{
    if (a == b && a != c)
        return true;
    else if (a == c && a != b)
        return true;
    else if (b == c && b != a)
        return true;
    else
        return false;
}
_Bool trdr(int a, int b, int c)
{
    if (c * c == a * a + b * b)
        return true;
    else if (a * a == b * b + c * c)
        return true;
    else if (b * b == a * a + c * c)
        return true;
    else
        return false;
}