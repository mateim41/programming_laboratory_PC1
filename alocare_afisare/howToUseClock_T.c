#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    clock_t start = clock();

    clock_t end = clock();
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %lfs\n", executionTime);
    return EXIT_SUCCESS;
}