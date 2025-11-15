#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[argc + 1])
{
    float x, y;
    char op; //+ - * /
    scanf("%f %f", &x, &y);
    scanf("%s", &op);
    switch (op)
    {
        case '+':
            printf("%f + %f = %f\n", x, y, x + y);
            break;
        case '-':
            printf("%f - %f = %f\n", x, y, x - y);
            break;
        case '*':
            printf("%f * %f = %f\n", x, y, x * y);
            break;
        case '/':
            printf("%f / %f = %f\n", x, y, x / y);
            break;
        default:
            printf("Valoare eronata\n");
    }


    return EXIT_SUCCESS;
}