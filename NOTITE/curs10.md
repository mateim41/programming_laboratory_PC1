# Structuri

![20251204_152723](https://github.com/user-attachments/assets/3dc858ac-b243-455b-805c-7ed62d9ca696)

![20251204_152258](https://github.com/user-attachments/assets/00992d9e-258c-4b87-967e-2616e22092b4)

Cum functioneaza __const__:

```c
int main(void)
{
    int a = 3;
    int b = 4;
    int *p1 = &a;
    *p1 = 4; // pot schimba valoarea de la adresa
    p1 = &b; // pot schimba adresa (= valoarea pointerului)

    const int* p2 = &a;
    // *p2 = 4; // nu pot schimba valoarea de la adresa (pt ca este const = read-only)
    p2 = &b; // pot schimba adresa (= valoarea pointerului)

    const int* const p3 = &a;
    // *p3 = 5; // nu pot schimba valoarea de la adresa (pt ca este const = read-only)
    // p3 = &b; // nu pot schimba adresa (= valoarea pointerului = const)
    return EXIT_SUCCESS;
}
```

### const

- ar trebui să fie folosit peste tot in cod, atunci când știm că variabilele pe care le folosim nu vor mai fi modificate

- asta ajuta in mai multe feluri:

    1. claritate pt user (stiu ca functia pe care o apelez nu va modifica valoarea argumentului)

    2. siguranta (mai putine buguri pentru ca variabilele nu pot fi modificate accidental)

    3. oportunitati de optimizare pentru compilator (info despre valorile imutabile - care nu se mia schimba pe durata programului ajuta compilatorul sa genereze assembly mai eficient)

<img width="1530" height="996" alt="image" src="https://github.com/user-attachments/assets/59b8da89-67e5-4ede-932a-2b5ab2adebc4" />

### restrict

De exemplu avem un program in care unele zone de memorie se pot suprapune (astfel compilatorul genereaza cod assembly foarte precaut), iar folosind tipul restrict ii spunem "trust me nu sunt zone de memorie overlapping" si genereaza cod mult mai eficient.
