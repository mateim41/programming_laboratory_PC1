#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    float a,b,c,x1,x2,d;
    printf("Introduceti coeficientii ec de grad 2: ");
    scanf("%f %f %f", &a, &b, &c);
    d=b*b-4*a*c;
    if(d<0) printf("Nerezolvabil \n");
    else if(d>0)
    {
        x1=(-b+sqrt(d))/(2*a);
        x2=(-b-sqrt(d))/(2*a);
        printf("Solutiile ecuatiei sunt %f, %f \n", x1, x2);
    }
    else 
    {
        x1=-b/2*a;
        printf("Solutia ecuatiei este %f\n",x1);
    }

    return EXIT_SUCCESS;
}