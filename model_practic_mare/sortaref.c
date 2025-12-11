#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sortare.h"

void *xmalloc(const size_t size);
student *alocareStudent()
{
    student *s = xmalloc(sizeof(student));
    s->first_name = xmalloc(NAME_SIZE * sizeof(char));
    s->last_name = xmalloc(NAME_SIZE * sizeof(char));
    return s;
}
student *citireStudent()
{
    student *s = alocareStudent();
    scanf("%d", &s->id);
    scanf("%s", s->first_name); // ce se intampla daca citesc mai mult de NAME_SIZE caractere?
    scanf("%s", s->last_name);
    scanf("%lf", &s->media);
    return s;
}
student *creareStudent(int id, char *first_name, char *last_name, double media)
{
    student *s = alocareStudent();
    s->id = id;
    strncpy(s->first_name, first_name, NAME_SIZE); // ma protejez de situatia in care in sursa avem mai multe caractere decat in destinatie
    strncpy(s->last_name, last_name, NAME_SIZE);
    s->media = media;
    return s;
}
void afisareStudent(student *Student)
{
    printf("ID: %d, Nume: %s, Prenume: %s, Medie: %.2lf\n", Student->id, Student->last_name, Student->first_name, Student->media);
}
void dealocareStudent(student *Student)
{
    free(Student->first_name);
    free(Student->last_name);
}

void swap(student **s1, student **s2)
{
    student *aux = *s1;
    *s1 = *s2;
    *s2 = aux;
}
void sortare1(student **vectorStudenti, const size_t nrStudenti)
{
    for (int i = 0; i < nrStudenti - 1; i++)
    {
        student *s1 = vectorStudenti[i];
        for (int j = i + 1; j < nrStudenti; j++)
        {
            student *s2 = vectorStudenti[j];
            if (s2->media > s1->media)
            {
                swap(&s1, &s2);
            }
        }
    }
}
// p1 = student**    p2 = student**
int compare(const void *p1, const void *p2)
{
    student *s1 = *(student **)p1;
    student *s2 = *(student **)p2;
    if (s1->media == s2->media)
    {
        return 0; // puteam sa pun alt criteriu
    }
    // pt if -> ? atc     : altfel
    return s1->media > s2->media ? -1 : +1;
}
void sortare2(student **vectorStudenti, const size_t nrStudenti)
{
    qsort(vectorStudenti, nrStudenti, sizeof(student *), compare);
}

void *xmalloc(const size_t size)
{
    void *v = malloc(size);
    if (v == NULL)
    {
        fprintf(stderr, "Eroare alocare\n");
        exit(EXIT_FAILURE);
    }
    return v;
}