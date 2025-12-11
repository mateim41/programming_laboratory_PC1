#ifndef SORTARE_H
#define SORTARE_H

#include <stddef.h>

#define NAME_SIZE 20

typedef struct
{
    int id;
    char *first_name;
    char *last_name;
    double media;
} student;

void *xmalloc(const size_t size);
student *alocareStudent();
student *citireStudent();
student *creareStudent(int id, char *first_name, char *last_name, double media);
void afisareStudent(student *Student);
void dealocareStudent(student *Student);
void sortare1(student **vectorStudenti, const size_t nrStudenti);

#endif