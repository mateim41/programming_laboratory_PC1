#include <stdio.h>
#include <stdlib.h>

#include "p21.h"

int main(void)
{
    vectorReal *vec = citireVector();
    
    char operatie;
    printf("Introduceti metoda de sortare: ");
    scanf(" %c", &operatie);
    prelucrareVector(vec, &operatie);

    dealocareStruct((vectorReal **)&vec);
    return EXIT_SUCCESS;
}
