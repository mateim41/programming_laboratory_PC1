# Tablouri multidimensionale. Matrici alocate static

```c
typedef int Vec[3];

typedef int Matrice[2][3];

// trb sa punem minim o dimensiune ca sa stim cate elem avem pe o linie; mat[][3]
void afisaremat(int *mat[3], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
}
```

```c
#define NROW 10
#define NCOL 10
typedef int intMatrix[NROW][NCOL];

void afisaremat(intMatrix mat, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
}
```