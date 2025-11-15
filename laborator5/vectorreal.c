#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void citire(double *v, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%lf", &v[i]);
}
void afisare(double v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2lf ", v[i]);
        if (i == n - 1)
            printf("\n");
    }
}
void avgreal(double *v, double *ma, int n)
{
    for (int i = 0; i < n; i++)
    {
        *ma += v[i];
    }
    *ma /= n;
}
double abatere(double *v, int n)
{
    double sum = 0, med;
    avgreal(v, &med, n);
    for (int i = 0; i < n; i++)
    {
        sum += (v[i] - med) * (v[i] - med);
    }
    return sqrt(sum / (n * (n - 1)));
}
void nrelem(double *x, int n)
{
    double med = 0;
    avgreal(x, &med, n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (x[i] < med)
            cnt++;
    printf("Numarul de elemente mai mici ca val medie este: %d\n", cnt);
}
int vector(double *x, double *y, int n)
{
    double med = 0;
    int cnt = 0;
    avgreal(x, &med, n);
    for (int i = 0; i < n; i++)
    {
        if (x[i] > med)
        {
            y[cnt++] = x[i];
        }
    }
    return cnt;
}
void init1(double *v, int n)
{
    for (int i = 0; i < n; i++)
        *(v + i) = 1;
}
double prodscalar(double *v, double *u, int n)
{
    double prod = 0;
    for (int i = 0; i < n; i++)
    {
        prod += v[i] * u[i];
    }
    return prod;
}
// calculam coef in main
int rezsistem(double A[2][3], double X[2][1], int n)
{
    double detA = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    if (detA != 0)
        return 1;
    else
    {
        double dcar = A[0][0] * A[1][2] - A[0][2] * A[1][0];
        if (dcar != 0)
        {
            return 3;
        }
        return 2;
    }
}