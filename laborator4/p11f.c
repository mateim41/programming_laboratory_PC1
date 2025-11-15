#include <stdio.h>
#include "p11.h"

void f1(double *a, double *b)
{
    *a = *a + 123.89;
    *b = *a * 25 - 469.20;
}