#ifndef P223_H
#define P223_H

#include <stddef.h>

double *Citire(size_t n);
void Afisare(double *v, size_t n);
int ApartineMultime(double *v, size_t n, double x);
double *Reuniune(double *A, double *B, size_t n, size_t m, size_t *lungime);
double *Intersectie(double *A, double *B, size_t n, size_t m, size_t *lungime);
double *DiferentaSimetrica(double *A, double *B, size_t n, size_t m, size_t *lungime);
char *transformareToASCII(long int x, size_t *size); // sir de caractere cu cifrele numarului si semn

#endif