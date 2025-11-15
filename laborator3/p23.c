#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int hi, mi, si, h, m, s, hf, mf, sf;
    /*
    19 23 46
    12 40 25
    31 63 71
    8 4 11
    */
    printf("Introduceti conectarea initiala si durata totala a conexiunii:");
    scanf("%d %d %d %d %d %d", &hi, &mi, &si, &h, &m, &s);
    hf = hi + h;
    sf = si + s;
    mf = mi + m;
    if (hf > 24)
    {
        hf -= 24;
    }
    if (sf >= 60)
    {
        mf += 1;
        sf -= 60;
    }
    if (mf >= 60)
    {
        hf += 1;
        mf -= 60;
    }
    printf("Momentul intreruperii conexiunii este: ora %d, minutul %d, secunda %d\n", hf, mf, sf);

    return EXIT_SUCCESS;
}