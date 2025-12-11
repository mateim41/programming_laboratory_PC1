#include <stdio.h>
#include <stdlib.h>

#include "sortare.h"

int main(void)
{
    int nrStudenti;
    scanf("%d", &nrStudenti);
    student **vectorStudenti = xmalloc(nrStudenti * sizeof(*vectorStudenti));
    for (int i = 0; i < nrStudenti; i++)
    {
        vectorStudenti[i] = citireStudent();
        afisareStudent(vectorStudenti[i]);
    }

    for (int i = 0; i < nrStudenti; i++)
    {
        afisareStudent(vectorStudenti[i]);
        dealocareStudent(vectorStudenti[i]);
    }
    return EXIT_SUCCESS;
}