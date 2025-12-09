# Structuri

## 1. Declaratie

```c
struct Person {
    char name[50];
    int age;
    float height;
};
```
In general:
```c
struct Nume {
    tip1 membru1;
    tip2 membru2;
    ...
    tipN membruN;
};
```

## 2. Declararea variabilelor de tip structura

```c
// struct nume_structura nume_variabila;
struct Person person1;
```
Declarare simulana (nerecomandat):
```c
// se declara structura Person si variabila person1
struct Person {
    char name[50];
    int age;
    float height;
} person1;
```

## 3. Initializarea structurilor

```c
// inainte de C23
struct Person person1 = {
    "John", 51, 1.85
};

// C23
struct Person person1 = {
    .name = "John", .age = 51, .height = 1.85
};
```
Vector de structuri:
```c
struct Person persons[] = {
    { "John", 51, 1.85 },
    { "Mary", 49, 1.76 }
};
```

## 4. Structuri ca parametru la functie

### Accesarea valorilor membrilor structurii
Accesul se face cu ajutorul punctului `.`
```c
void printPerson(struct Person p) {
    printf("name: %s\n", p.name);
    printf("age: %d\n", p.age);
    printf("height: %f\n", p.height);
}
```

Daca avem pointer la structura, accesul se face cu `->`:
```c
void printPerson(struct Person *p) {
    printf("name: %s\n", p->name);
    printf("age: %d\n", p->age);
    printf("height: %f\n", (*p).height);
}
```
(sau, se face dereferentierea pointerului si se foloseste `.`)

Citirea se face la fel ca variabilele normale:
```c
struct Person p;
scanf("%s", &p.name);
scanf("%d", &p.age);
scanf("%f", &p.height);
```

### Avantajele transferului structuri ca argument prin pointer:
```c
void functie(struct Person *p);
```
Avantajul este ca nu se copiaza structura in sine (care poate fi mare ca nr de octeti, in functie de membrii structurii), ci _se copiaza doar adresa (pointerul)_. Asta duce la cod mai eficient.

## 5. Structuri ca tip de return

Avantajul este ca pot returna din functie mai multe date (grupate ca si structura).

```c
struct Statistics {
    double minim;
    double maxim;
    double medie;
};

struct Statistics calculStatistic(double *vector, size_t size) {
    struct Statistics stats { 
        .minim = vector[0],
        .maxim = vector[0],
        .medie = vector[0]
    };
    for (int i = 0; i < size; ++i) {
        stats.medie += vector[i];
        if (stats.minim > vector[i]) {
            stats.minim = vector[i];
        }
        if (stats.maxim <> vector[i]) {
            stats.maxim = vector[i];
        }
    }
    return stats;
}
```

## 6. Sinonime cu typedef

Prin `typedef` eu pot defini un tip care sa fie sinonim cu structura mea.

```c
struct _Person {
    char name[50];
    int age;
    float height;
};

// Person => struct _Person
typedef struct _Person Person;
```
Apoi pot folosi structura prin sinonimul `Person` fara a mai avea nevoie de keyword-ul `struct`:
```c
Person p1 = { ... };
void printPerson(Person p);
// etc
```
Daca nu intentionez sa ma folosesc de structura, sau vreau sa definesc un _tip opac_ ("opaque type"):
```c
typedef struct {
    char name[50];
    int age;
    float height;
} Person;
```
Apoi ma folosesc de `Person` fara `struct`.

```c
typedef struct Person {
    char name[50];
    int age;
    float height;
} Person;
```

## 7. Utilizarea structurilor in general

- ca sa modelez obiecte din lumea reala

```c
struct VectorDouble {
    double *valori;
    size_t size;
};

struct MatriceIntregi {
    int **valori;
    size_t nrLinii;
    size_t nrColoane;
};

struct Adresa {
    char oras[50];
    char judes[50];
    int codPostal;
};

struct Persoana {
    char nume[50];
    char prenume[50];
    int cnp;
    struct Adresa adresa; // structura ca membru al altei structuri
};

struct Persoana persoana = {
    "Popescu", "Ion", 1809713456789, { "Iasi", "IS", 123456 }
};

// sau in C23
struct Persoana persoana = {
    .nume = "Popescu",
    .prenume = "Ion",
    .cnp = 1809713456789, 
    .adresa = {
        .oras = "Iasi",
        .judet = "IS",
        .codPostal = 123456
    }
};

printf("nume: %s, oras: %s\n", persoana.nume, persoana.adresa.oras);
```