#ifndef P11_H
#define P11_H

// Citirea unui vector de întregi
int *pcitireVector2(int n);

// Afișarea vectorilor
void pafisareVectorIntregi(int *a, int n);
void pafisareVectorReali(double *a, int n);

// Calcularea vectorului cu valorile medii (folosind media aritmetică)
double *vectorMedie(int *a, int *b, int n);

// Calcularea mediei aritmetice a valorilor elementelor unui vector
double mediaAritmeticaVector(double *a, int n);

// Calcularea mediei aritmetice a două numere întregi
double mediaAritmeticaIntregi(int a, int b);

// Calcularea sumei valorilor elementelor unui vector de reali
double sumaVectorReali(double *a, int n);

#endif