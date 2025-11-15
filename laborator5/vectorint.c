#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include <stdbool.h>
#include "vectorint.h"

void citire(int v[], size_t n)
{
    // v -> adresa la primul element(deci pointer)
    //&v[0] -> luam explicit adresa primului element
    //&v[1] -> luam explicit adresa elementului 1
    // v+i -> adresa elementului i
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        // echivalent cu scanf("%d", v+i)
    }
}
void afisare(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
        // printf("%d", *(v+i)); //echivalent
    }
    printf("\n");
}
void suma(int a[], int b[], int suma[], int n)
{
    for (int i = 0; i < n; i++)
        suma[i] = a[i] + b[i];
    //*(suma+i) = *(a+i)+ *(b+i); //echivalent
}
void produs(int *a, int *b, int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = 0;
        if (*(a + i) != 0 && *(b + i) != 0)
        {
            p[i] += a[i] * b[i];
        }
        else
            p[i] += a[i] + b[i];
    }
}
void medaritm(int *v, double *ma, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += v[i];
    *ma = (float)s / n;
}
int sumaelem(int *v, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += v[i];
    return s;
}
int vmax(int *v, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > max)
            max = v[i];
    }
    return max;
}
int vmin(int *v, int n)
{
    int min = 1000000;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < min)
            min = v[i];
    }
    return min;
}
void medgeom(int *v, double *mg, int n)
{
    int s = 1;
    for (int i = 0; i < n; i++)
        s *= v[i];
    *mg = pow(s, 1.0 / n);
}
int distinct(int a[], int b[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (gasit(a, n, a[i]) && gasit(b, n, a[i]) == 0)
        {
            b[cnt++] = a[i];
        }
    }
    return cnt;
}
_Bool gasit(int a[], int n, int el)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == el)
            return true;
    }
    return false;
}
void ordonareBule(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                int aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
    }
}