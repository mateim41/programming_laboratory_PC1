#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i,n,s=0,x;
    printf("Introduceti numarul de numere: ");
    scanf("%d",&n);
    for(i=n;i>0;i--)
    {
        scanf("%d", &x);
        s=s+x;
    }
    printf("Suma celor n numere este %d \n",s);

    return EXIT_SUCCESS;
}