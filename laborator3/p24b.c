#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float tsfgrade(int C);
/*
9C=5(F-32)
(9/5)C=F-32
(9/5)C+32=F
*/
int main(void)
{
    float F;
    unsigned cnt;
    int i;
    printf("Pasul este: ");
    scanf("%u", &cnt);
    for (i = 400; i >= 0; i = i - cnt)
    {
        F = tsfgrade(i);
        printf("%d grade Celsius = %f grade Fahrenheit\n", i, F);
    }

    return EXIT_SUCCESS;
}
float tsfgrade(int C)
{
    float F = (9.0f / 5) * C + 32;
    return F;
}