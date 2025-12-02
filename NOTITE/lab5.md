# Tablouri

## 1.Declaratie

Vector (tablou) cu 5 elemente de tip int
1.Dimensiunea statica(cunoscuta la compilare)

```c
//vector care contine 5 elemente de tip intreg
int v[5];
```

#### 2. Dimensiunea dinamica(cunoscuta la rulare)
```c
int n;
printf("introduceti dimensiunea vectorului: ");
scanf("%d",&n);
int v[n]; //VLA (Variable Length Array, >=C99)
```

#### 3. Inainte de C99
```c
#define N 100 //dimensiunea maxima
int v[N];    //vector de dimensiune maxima

int n;
printf("dimensiunea actuala: ");
scanf("%d" ,&n);
//apoi utilizam doar primele n elemente din v (n<N)
```


## 2. Initializare
```c
int a[3] = {1, 2, 3};
int b[3] = {[2]=1, [0]=2, 3};// b[3] = {2, 3, 1}
int c[] = {1, 2, 3}//dimensiune dedusa din valoarea de initializare

int v[3];
v[0] = 2;
v[1] = 5;
v[2] = 9;
```

#### 3. Utilizare
Indexarea in vectori

Indexul incepe intotdeauna de la 0

```c
int v[n];
//elementele vor avea index: 0, 1, 2,...,n-2,n-1

for(int i = 0;i < n;i++)
{
    v[i] = 2 * i;
}

int v[n+1];                 //nerecomandat
for(int i = 1;i <= n;i++)   //nerecomandat
{                           //nerecomandat
    v[i] = 2 * i;           //nerecomandat
}                           //nerecomandat
```

Vector ca parametru in functie

```c
int v[n];

void afisare(int v[], int n)
{
}
//echivalent cu 
void afisare(int *v, int n)
{
}
```
Echivalenta array <-> pointer
Un vector `int v[5]` este echivalent cu `int *v`