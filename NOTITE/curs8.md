# Matrici

![20251120_143659](https://github.com/user-attachments/assets/12abe3fa-58be-4535-a1f1-f3bf4a1bfde7)

![20251120_143648](https://github.com/user-attachments/assets/82d1f721-2f16-4644-a7b0-76320dcce7f0)

![20251120_144512](https://github.com/user-attachments/assets/e55eff24-4da2-45bb-89d3-0641b3042797)

```c
int m1[ROWS][COLS]; // matrice alocata static
int **m2 = malloc(ROWS * sizeof(int*));
int *m3 = malloc(ROWS * COLS * sizeof(int));
for(int i = 0;i < ROWS; i++)
{
    m2[i] == malloc(COLS * sizeof(int));
}

for(int i = 0;i < ROWS; i++)
{
    for(int j = 0;j < COLS; j++)
    {
        m1[i][j] = i + j;
        m2[i][j] = i + j;
        m3[i * COLS + j] = i + j;
    }
}
for(int i = 0;i < ROWS; i++)
{
    for(int j = 0;j < COLS;j++)
    {
        printf("(%d, %d, %d)", m1[i][j], m2[i][j], m3[i * COLS + j]);
    }
    printf("\n");
}

```
