#ifndef VECTORREAL_H
#define VECTORREAL_H

void citire(double *v, int n);                  // citirea unui sir de numere reale
void afisare(double v[], int n);                // afisarea unui sir de numere reale cu 2 zecimale
double avgreal(double *v, double *ma, int n);   // val medie a unui sir de nr reale
double abatere(double *v, int n);               // abaterea medie patratica
void nrelem(double *x, int n);                  // nr elem care nu depasesc val med
int vector(double *x, double *y, int n);        // vector nou cu valorile mai mari decat val medie
void init1(double *v, int n);                   // initializam vectorul cu 1
double prodscalar(double *v, double *u, int n); // prod scalar dintre elem a doi vectori
int rezsistem(double A[2][3], double X[2][1]);       // matricele sistemului

#endif