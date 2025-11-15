#ifndef VECTORINT_H
#define VECTORINT_H

// v[] este echivalent cu *v
// compilatorul face automat conversia v[] -> *v (acelasi lucru)
void citire(int v[], int n);//citim un vector
void afisare(int *v, int n);//afisam un vector
void suma(int a[], int b[], int suma[], int n);//suma elementelor intr-un nou vector
void produs(int *a, int *b, int *p, int n);
void medaritm(int *v, double *ma, int n);//media aritmetica a elementelor unui vector
int sumaelem(int *v, int n);//suma elementelor unui singur vector
int vmax(int *v, int n);//valoarea maxima dintr-un vector
int vmin(int *v, int n);//valoarea minima dintr-un vector
void medgeom(int *v, double *mg, int n);//media geometrica a elementelor unui vector
int distinct(int a[], int b[], int n);//gasim elementele distincte din sirul a si le punem in b si returnam nr de elemente ale vectorului final
_Bool gasit(int a[], int n, int el);//cautam un element in a
void ordonareBule(int *a, int n);//ordonam crescator un vector

#endif