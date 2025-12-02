# Vectori

An __array__ is a _collection of elements_ of the same data type stored in contiguous memory locations. Arrays allow you to store multiple values under a single variable name, accessed via indices.

![20251113_142409](https://github.com/user-attachments/assets/ee79e749-5807-4dee-8ab8-14f760cce02f)

    - Nu pot aloca pe stiva dimensiuni foarte mari
    - Odata ce declar un vector static nu mai pot redimensiona vectorul mai tarziu

    - Putem accesa mai multe valori sub acelasi nume

## Main characteristics

__Contiguous memory__

    All elements are stored sequentially in memory

__Zero-indexed__

    First element is at index 0, last at index n-1

__Fixed size__

    Size must be known at compile time (for static arrays)

__Same type__

    All elements must be of the same data type

## Array initialization

5. Digit separator(C23)

```c
int large_array[1'000'000]; // More readable than 1000000
int values[] = {1'000, 2'000, 3'000};
```

### Variable length arrays (VLAs)

VLAs allow array sized determined at runtime (introduced in C99, made optional in C11, remains optional in C23):

```c
void process_data(size_t n)
{
    int dynamic_arr[n]; // Size determined at runtime
}
```

Memoria tot pe stiva este alocata deci daca n e prea mare o sa ramanem fara memorie.

## Array decay to pointer

![20251113_151358](https://github.com/user-attachments/assets/ec156702-916d-47de-a0d6-5536be44d4c6)

Fiindca vectorul se degradeaza la pointer nu trebuie sa folosesc & cand folosesc numele vectorului.

```c
int v[5] = {1, 2, 3, 4, 5};

int *p = v; // adresa primului element din vector
// SAU  
int *pv = &v[0];
```

```c
// afisare ca matrice
int main(void)
{
int rows = 3;
int cols = 3;
int mat[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

return exit_succes;
}
// Mod 1

void afisare1(int v[], int rows, int cols)
{
    int n = rows * cols;
    for(int i = 0;i < n;i++)
    {
        printf("%d ", v[i]);
        if((i+1) % cols == 0)
        {
            printf("\n");
        }
    }
}

// Mod 2

void afisare(int v[], int n)
{
    for(int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
void afisare2(int v[], int rows, int cols)
{
    int n = rows * cols;
    for(int *p = v; p < v + n; p += cols) {
        afisare(p, cols);
    }
}
```

    Pentru mod 2

![20251113_152944](https://github.com/user-attachments/assets/3584da98-07bd-48f4-9926-a5e86bf34a05)

```c
// Mod 3

void afisare3(int v[], int rows, int cols)
{
    int n = rows * cols;
    for(int i = 0; i < n; i+=cols)
    {
        afisare(v + i, cols);
    }
}
```

## Common array operations

### Iterating through arrays

```c
int arr[5] = {1, 2, 3, 4, 5};

// Method 1: Index-based
for(int i = 0; i < 5; i++)
{
    printf("%d ", arr[i]);
}

// Method 2: Pointer arithmetic
for(int *p = arr; p < arr + 5; p++)
{
    printf("%d ", *p);
}
```

### Calculating array size

```c
// Daca nu s-a degradat vectorul la pointer

int arr[10];
size_t length = sizeof(arr) / sizeof(arr[0]); // result: 10
```

### Size should be predefined

```c
#define ARRAY_SIZE 100
int data[ARRAY_SIZE]
```

Strings (char arrays) should have space for the string terminator `\0`.

```c
char string[20] = "Hello"; // enough space for '\0'
```

### No assignment

___Cannot assign one array to another directly___
