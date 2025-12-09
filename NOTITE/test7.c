#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("introduceti dimensiunea vectorului: ");
    size_t n;
    scanf("%ld", &n);
    printf("am citit n = %ld\n", n);

    double v[n]; // VLA cu dimensiune variabila
    printf("dimensiune vector = %ld\n", sizeof(v) / sizeof(v[0]));
    for (int i = 0; i < n; ++i)
    {
        v[i] = i;
    }
    // imi da segmentation fault cand pun valoarea prea mare

    return EXIT_SUCCESS;
}