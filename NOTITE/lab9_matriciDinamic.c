#include "stdio.h"
#include "stdlib.h"

void **citireMatrice(int n, int m);
void afisareMatrice(int **matrice, int n, int m);

void **alocareMatrice(int n, int m);
void dealocareMatrice(void **v, int n);

int main(void)
{
    // aloc un vector de intregi cu n elemente
    int n = 3; // linii
    int m = 3; // coloane

    int **matrice; // pointer la pointer la intreg
    matrice = (int **)malloc(n * sizeof(*matrice));
    free(matrice);

    matrice = nullptr;
    return EXIT_SUCCESS;
}

void **alocareMatrice(int n, int m)
{
    // *mat => trec de la int** la int* => sizeof(*mat) = sizeof(int *)
    void **mat = malloc(n * sizeof(*mat));
    for (int i = 0; i < n; i++)
    {
        mat[i] = malloc(m * sizeof(*mat));
    }
}
void **citireMatrice(int n, int m)
{
    int **mat = (int **)alocareMatrice(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", *(mat + i) + j);
        }
    }
    return mat;
}

void afisareMatrice(int **matrice, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

void dealocareMatrice(void **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        mat[i] = nullptr;
    }
    free(mat);
    mat = nullptr;
}
