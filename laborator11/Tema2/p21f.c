#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "p21.h"

void *xmalloc(const size_t size);
void *xcalloc(const size_t nrElem, const size_t size);
void *xrealloc(void *v, const size_t size);

vectorReal *citireVector()
{
    vectorReal *v = (vectorReal *)xmalloc(sizeof(*v));

    char *s = xmalloc(20 * sizeof(char));
    printf("Cititi numele vectorului: ");
    scanf("%19s", s);       // limitez citirea la 19 caractere ca sa fie loc de \0 - null terminator
    size_t l = strlen(s);   // Matei = 5
    s = xrealloc(s, l + 1); // adaug \0 - null terminator
    v->nume = s;
    /*
        puteam sa fac

        char s[20];
        scanf("%19s", s);
        int l = strlen(s);
        v->nume = xmalloc((l + 1) * sizeof(char));
        strcpy(v,s);
    */

    printf("Numarul de elemente al vectorului: ");
    scanf("%zd", &v->nr_elemente);

    v->vector = xcalloc(v->nr_elemente, sizeof(*v->vector));
    printf("Cititi componentele vectorului: ");
    for (int i = 0; i < v->nr_elemente; i++)
    {
        scanf("%lf", &v->vector[i]);
    }
    return v;
}
void afisare(vectorReal *vec)
{
    printf("Vectorul %s are, dupa sortare, componentele: ", vec->nume);
    for (int i = 0; i < vec->nr_elemente; i++)
    {
        printf("%.3lf ", vec->vector[i]);
    }
    printf("\n");
}
void dealocareStruct(vectorReal **vec)
{
    if (vec == NULL || *vec == NULL)
    {
        return;
    }
    vectorReal *v = *vec;
    free(v->nume);
    free(v->vector);
    free(v);
    *vec = NULL;
}
// transform variabila intr-un unsigned int si dupa fac suma cifrelor
int sumCif(double x)
{
    x = fabs(x);
    x = floor(x);
    int a = x;

    int s = 0;
    while (a)
    {
        s += a % 10;
        a /= 10;
    }
    return s;
}
void swap(double *x, double *y)
{
    double aux = *x;
    *x = *y;
    *y = aux;
}
void ordonareCrescValoare(vectorReal *vec)
{
    for (int i = 0; i < vec->nr_elemente - 1; i++)
    {
        for (int j = i + 1; j < vec->nr_elemente; j++)
        {
            if (vec->vector[i] > vec->vector[j])
            {
                swap(&vec->vector[i], &vec->vector[j]);
            }
        }
    }
}
void ordonareCrescSumaCifModul(vectorReal *vec)
{
    // 19.3 42.2 75.7 -111.9 22.0
    for (int i = 0; i < vec->nr_elemente - 1; i++)
    {
        int s1 = sumCif(vec->vector[i]);
        for (int j = i + 1; j < vec->nr_elemente; j++)
        {
            int s2 = sumCif(vec->vector[j]);
            if (s1 > s2)
            {
                swap(&vec->vector[i], &vec->vector[j]);
                s1 = sumCif(vec->vector[i]);
            }
        }
    }
}
void prelucrareVector(vectorReal *vec, const char *operatie)
{
    switch (*operatie)
    {
    case '1':
    {
        printf("Ati ales sortarea cresc in functie de valoarea componentelor.\n");
        ordonareCrescValoare(vec);
        afisare(vec);
        break;
    }
    case '2':
    {
        printf("Ati ales sortarea cresc in functie de suma cifrelor modulului partii intregi.\n");
        ordonareCrescSumaCifModul(vec);
        afisare(vec);
        break;
    }
    default:
        printf("Optiune de sortare gresita.\n");
        break;
    }
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
void *xcalloc(const size_t nrElem, const size_t size)
{
    void *v = calloc(nrElem, size);
    if (v == NULL)
    {
        fprintf(stderr, "Eroare alocare\n");
        exit(EXIT_FAILURE);
    }
    return v;
}
void *xrealloc(void *v, const size_t size)
{
    void *p = realloc(v, size);
    if (p == NULL)
    {
        fprintf(stderr, "Eroare realocare\n");
        free(v);
        v = NULL;
        exit(EXIT_FAILURE);
    }
    return p;
}