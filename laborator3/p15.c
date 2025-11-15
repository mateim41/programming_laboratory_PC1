#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x,p=1;
    scanf("%d",&x);
    while(x!=0)//while(scanf("%d",&x)!=0)
    {
        p*=x;
        scanf("%d",&x);
    }
    printf("Produsul numerelor este %d \n",p);

    return EXIT_SUCCESS;
}