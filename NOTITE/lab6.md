# Pointeri

## Declaratie
Un pointer este o __varibila__ care are ca valoare __adresa__ altei variabile.

```c
int *p; // declar un pointer la intreg
        // tipul variabilei p este de tip int*
        // valoarea va fi aleatorie (random)
int x = 23; // variabila x de tip intreg (int)
p = &x; //p ia ca valoarea adresa lui x

float y = 6;
float *py = &y;

int v[3] = {1, 2, 3};
int *pv = v;

int a = pv[1];
int b = v[1];

// v -> decay to pointer -> int*
// (v este vazut ca pointer la adresa primului element)

int *pvv = &v[0];
```

## Pointer la pointer(la pointer, etc.)
Declararea unui pointer este de forma: `tip *nume`
```c
// TIP = int
int *p; // => pointer la int

// TIP = int*
int **q= &p;
// q pointer la o variabila de tip int*


int a = 5;

int *p = &a;
int **q = &p;
int ***r = &q;

// Afirmatii despre p si q:
// - p are ca valoare adresa lui a
// - *p este valoarea lui a
// - q are ca valoare adresa lui p
// - *q este valoarea lui p care este adresa lui a
// - **q este valoarea lui a

printf("Valoarea lui p (= adresa lui a): %p\n", p);
printf("Valoarea lui *p (= valoarea lui a): %d\n", *p);

printf("Valoarea lui q (= adresa lui p): %p\n", q);
printf("Valoarea lui *q (= valoarea lui p = adresa lui a): %p\n", *q);

printf("Valoarea lui r (= adresa lui q): %p\n", r);
printf("Valoarea lui *r (= valoarea lui q = adresa lui p): %p\n", *r);
```

![20251113_084018-1](https://github.com/user-attachments/assets/d2ffc7d0-264c-4ff3-8132-ac07926cf7eb)

## Array decay to pointer
Orice vector de tip `int v[]` este vazut ca un `int *`
```c
int v[5] = {4, 3, 2, 1, 0}; // declarat in main(de exemplu)

void afisare(int v[]. int n)
{
    // v aici este un pointer
    // in interiorul functiei v este int*
}
// functia de mai sus e ca si cum ar fi scrisa
void afisare(int *v, int n)
{
    // cod afisare ...
}
```

## Utilizare

### 1. Un pointer trebuie initializat 
```c
int *p = nullptr; // c23
int *q = NULL; // (inainte de c23)
```
### 2. Dereferentierea este legala doar daca adresa este valida
```c
int *p = nullptr; // sau NULL, sau 0

int a = *p;  // ILEGAL
            // nu avem voie sa dereferentiem un pointer null
```
