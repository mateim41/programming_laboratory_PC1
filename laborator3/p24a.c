#include <stdio.h>
#include <stdlib.h>

float transftemp(int F);
int main(void)
{
    float C;
    for (int i = 300; i >= 0; i -= 10)
    {
        C = transftemp(i);
        printf("%d Fahrenheit = %f Celsius\n", i, C);
    }

    return EXIT_SUCCESS;
}
float transftemp(int F)
{
    float grC = (5.0f / 9) * (F - 32);
    return grC;
}