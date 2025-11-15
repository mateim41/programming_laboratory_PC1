#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int hi, mi, si, hf, mf, sf, h, m, s;
    bool ok = true;
    /*
    19 23 46
    16 43 40

    19 23 46
    19 43 40
    */
    printf("Data conectarii si data deconectarii este: ");
    scanf("%d %d %d %d %d %d", &hi, &mi, &si, &hf, &mf, &sf);
    if (hi < hf)
    {
        if (sf < si)
        {
            mf -= 1;
            s = 60 + sf - si;
        }
        else
        {
            s = sf - si;
        }
        if (mf < mi)
        {
            hf -= 1;
            m = mf + 60 - mi;
        }
        else
        {
            m = mf - mi;
        }
        h = hf - hi;
    }
    else if (hi > hf)
    {
        if (sf < si)
        {
            mf -= 1;
            s = sf + 60 - si;
        }
        else
        {
            s = sf - si;
        }
        if (mf < mi)
        {
            hf -= 1;
            m = mf + 60 - mi;
        }
        else
        {
            m = mf - mi;
        }
        h = 24 - hi + hf;
    }
    else
    {
        h = 0;
        if (sf < si)
        {
            mf -= 1;
            s = sf + 60 - si;
        }
        else
        {
            s = sf - si;
        }
        if (mf < mi)
        {
            ok = false;
        }
        else
        {
            m = mf - mi;
        }
    }
    if (ok == true)
        printf("Durata conexiunii este de %d ore, %d minute si %d secunde.\n", h, m, s);
    else
        printf("Fals\n");

    return EXIT_SUCCESS;
}