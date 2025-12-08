#include <stdio.h>
#include <stdlib.h>

#include "punct.h"

int main(void)
{
  /*
    PUNCT a, b;
    printf("Cititi cele doua puncte:\n");
    scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y);
    printf("\n");
    double dist = distanta(a, b);
    printf("Distanta dintre cele doua puncte este: %lf\n\n", dist);
    PUNCT c = simetric(a); // simetricul lui a fata de Ox
    printf("Simetricul lui a fata de Ox este: %lf %lf\n", c.x, c.y);
  */
  PUNCT a = {2, 3};
  PUNCT b = {4.8, 7.8};

  PUNCT c = simetric(a);
  PUNCT *p = &b;

  printf("a= ");

  return EXIT_SUCCESS;
}