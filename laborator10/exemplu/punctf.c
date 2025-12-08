#include <math.h>
#include <stdio.h>

#include "punct.h"

double distanta(PUNCT a, PUNCT b)
{
  return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
PUNCT simetric(PUNCT a)
{
  PUNCT b;
  b.x = -a.x;
  b.y = -a.y;
  // return b;
  return (PUNCT){-a.x, -a.y};
}
void afisare(PUNCT a)
{
  printf("%lf %lf\n", a.x, a.y);
}
