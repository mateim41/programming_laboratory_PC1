# Alocare dinamica

## Alocare statica

Folositoare atunci cand cunoastem de la inceput dimensiunile (marimile) cu care vom lucra in program.

### Avantaje

- memoria se elibereaza automat (nu persista)
- alocarea pe stiva este foarte rapida

### Dezavantaje

- memoria este alocata pe stiva
- memoria nu persista
- memoria alocata pe stiva nu poate fi returnata ca functie (ca pointer)
- nu am siguranta ca capacitatea stivei este suficienta
- vectorii alocati pe stiva nu mai pot fi redirectionati

```c
int *f(int n)
{
    // int v[100]
    int v[n]; // vectorul v nu exista decat in interiorul functiei
    for(int i = 0; i < n; i++)
    {
        scanf("%d", v[i]);
    }
    return v;
}

void citire(int *v, int n)
{
    // fac citirea aici
}

int main(void)
{
    int n = 5;
    int *v = f(n); // invalid -> v nu mai pointeaza la ceva valid
    // ilegal sa folosesc v pt ca obiectul pointat nu mai exista
}
```

## Alocare dinamica

Atunci cand alocarea statica este nepotrivita sau insuficienta, putem recurge la **alocarea dinamica**, care ofera maximul de flexibilitate si robustete.

De exemplu, prin alocare dinamica eu pot verifica daca am primit memoria ceruta.

```c
// functia f1 este gresita -> nu pot returna un pointer la memoria pe stiva
// pentru ca v[n] nu mai exista la iesirea din functie (nu persista)
int *f1(int n)
{
    // int v[100]
    int v[n]; // vectorul v nu exista decat in interiorul functiei
    for(int i = 0; i < n; i++)
    {
        scanf("%d", v[i]);
    }
    return v;
}

// functia f2 este corecta, pentru ca memoria alocata dinamica persista
// (nu se dealoca / elibereaza automat)
int *f2(int n)
{
    int *v = malloc(n * sizeof(int));
    // verific daca alocarea s-a facut cu succes
    if (v == nullptr) { // NULL, 0
        fprintf(stdderr, "eroare alocare");
        // putem printa erori in canalul separat
        // chestii care nu tin de logica programului
        exit(EXIT_FAILURE);
    }
    for(int i = 0;i < n;i++)
    {
        scanf("%d", v[i]);
    }
    return v;
}
```

### Avantaje

- memoria persista (pointerul poate fi returnat din functie / memoria poate fi alocata in interiorul functiei)
- alocarea se face pe memoria heap (nu pe stiva) unde este mult mai mult spatiu
- zona de memorie alocata poate fi redimensionata mai tarziu (cu functia `realloc`)
- avem maximul de flexibilitate si robustete in utilizare
- semnaturile functiilor sunt mai clare (intentia este mai clara) 
  (API = application programming interface)


### Dezavantaje

- alocarea dinamica e (putin) mai lenta (functia malloc dureaza mai mult decat o simpla alocare pe stiva)
- memoria trebuie eliberata manual (fiecare `malloc` ar trebui insotit de un `free`)

### Functii pentru alocarea dinamica

1. `malloc`

```c
int n = 10;
int *v = malloc(n * sizeof(int));
if (v == nullptr) {
    // eroare: nu s-a putut face alocarea (vezi mai sus)
}
// folosim v... (continutul memoriei este random)
```

2. `calloc`

```c
int n = 10;
int *v = calloc(n, sizeof(int));
if (v == nullptr) {
    // eroare: nu s-a putut face alocarea (vezi mai sus)
}
// folosim v... (continutul memoriei este pus pe zero)
```

3. `realloc`

```c
int n = 10;
int *v = malloc(n * sizeof(int));
if (v == nullptr) { /* eroare alocare */ }

int n = 20;
int *u = realloc(v, n); // incercam sa redimensionam
// MEREU facem un pointer nou si dupa il punem in cel initial
if (u == nullptr) { /* eroare alocare */ }
v = u; // doar dupa verificare
```

4. `free`

```c
int n = 10;
int *v = malloc(n * sizeof(int));
if (v == nullptr) { /* eroare alocare */ }
// ...folosesc v... etc.
// la final memoria trebuie dealocata (eliberata)
free(v); // eliberam memoria
v = nullptr; // v este pointerul NULL

int a = *v; // eroare pt ca v nu mai pointeaza la o adresa valida
            // (pt ca adresa a fost eliberata cu free)
```

    Ilegal  sa compar pointeri la zone diferite de memorie
    (nu am cum sa stiu unde in memorie se afla)

![alt text](image-1-1.png)

![alt text](image_2-1.png)

![alt text](<Screenshot 2025-11-15 142622-1-1.png>)

![alt text](image_1-1.png)
