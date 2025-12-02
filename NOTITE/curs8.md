# Matrici

![alt text](20251120_143659.jpg) 

![alt text](20251120_143648.jpg)

![alt text](20251120_144512.jpg)

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
