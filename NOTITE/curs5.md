# Informatii test S6(6 nov 2025)
    tablouri, pointeri
# Curs 
Booleans are just fancy names for 0 and 1

We can do
```c
int v[2];
v[0]=5;   v[false]=5;
v[1]=9;   v[true]=9;
```

### Short-circuit evaluation
```c
if(a==b && b==c) //Expr1 && Expr2
//expr1 = fals -> ies din if; nu e nevoie sa verific si cea de-a doua expresie
if(a==b || a==c)
//expr1 = true -> analog ies din if
```

### Ternary (condition) operator
```c
int min(int a, int b)
{
    return a < b ? a : b
}
// ? (True) -> return a
// : (Fals) -> return b
```
Se comporta tot ca un if, dar pot scrie totul pe o singura linie mai compact

### Order of evaluation
ex: f(a)+ g(b)

Nu exista o ordine prestabilita pentru ordinea in care se efectuaza operatia. Totul depinde de compilator/versiune etc.

`printf("%g and %g\n", f(a), f(b));` Nu stim daca prima data se evalueaza f(a) sau f(b)

    Don't rely on side effects for your program!!!

### Key takeaways
**Narrow integers: short, char etc.** sunt promovate automat la signed int
```c
char a = 3;
char b = 4;

auto c = a + b; // c = int
printf("%ld %ld %ld", sizeof(a), sizeof(b), sizeof(c));
//1 1 4
//char este pe 1 byte, dar inainte de aritmetica narrow integers sunt promovati la signed int
//auto imi determinat automat tipul variabilei
```

    Toate variabilele trebuie initializate!
### Different uses for data types
**`size_t`** - pentru marimi care nu au semn; spre ex la vectori declaram nr maxim de elemente __size_t n__

**`ptrdiff_t`** - pentru aritmetica cu pointeri in caz ca avem si valori negative 

**`unsigned`** - pentru cantitati mici fara semn

**`signed`** - pentru cantitati mici cu semn

**`double`** - for floating-point calculation

    Pentru problema cu durata unei conexiuni puteam folosi headerul <time.h>

Nu putem folosi o functie de un anumit tip pentru a lucra cu variabile de un tip diferit.
```c
void afisare(int v[], int n);
float u[]={1.2, 3.4, 5.9, 6.9};
int n;

afisare(u,n);
//NU FUNCTIONEAZA
//trebuie creata o functie noua pentru a lucra cu float
void afisare_float(float u[], int n);
```
```c
//cum pot sa evit sa folosesc afisare_int, afisare_float
typedef void(*fptr)(void*);// pointer la functii
void print_int(void *v)
{
    int *a = *(int *)v;// cast
    //un pointer la int, interpretand-ul pe v 
    printf("%d ", *a);
}

void print_float(void *v)
{
    float *p = *(float*)v;
    printf("%f ", *p);
}

void afisare(void *v, size_t s, size_t n, fptr f)
{
    char* p = (char*)v;
    for(int i = 0; i < n; ++i)
    {
        f(p);
        p +=s ;
    }
}

int main(void)
{
    int v[3] = {3, 4, 5};
    afisare(v, sizeof(int), sizeof(v)/sizeof(int), print_int);

    float u[4] = {2.0, 3.2, 4.5, 8.7};
    afisare(u, sizeof(float), sizeof(u)/sizeof (float), print_float);
}
```
    !!! un pointer la void poate duce in orice alt tip