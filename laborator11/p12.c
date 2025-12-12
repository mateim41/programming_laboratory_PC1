#include <stdio.h>
#include <stdlib.h>

#include "p11.h"

int main(void)
{
    size_t lungime_sir;
    printf("Lungimea sirului de numere complexe: ");
    scanf("%zd", &lungime_sir);
    printf("\n");

    printf("Sirul de numere complexe:\n");
    complex **z_sir = citireSirImaginar(lungime_sir);

    complex *s_par = sumaSir((const complex **)z_sir, lungime_sir, 0);
    complex *s_impar = sumaSir((const complex **)z_sir, lungime_sir, 1);
    complex *s_total = suma((const complex *)s_par, (const complex *)s_impar);
    printf("Suma elementelor din sir: %lf + %lfi\n", s_total->real, s_total->imag);
    printf("Suma indecsilor impari este: %lf + %lfi\n", s_impar->real, s_impar->imag);
    printf("Suma indecsilor pari este: %lf + %lfi\n", s_par->real, s_par->imag);

    double *sir_module = modulSir((const complex **)z_sir, lungime_sir);
    printf("Sirul modulelor elementelor sirului de nr complexe:\n");
    for (int i = 0; i < lungime_sir; i++)
    {
        printf("%lf ", *(sir_module + i));
    }
    printf("\n");

    double *argumenteNrComplexe = argumenteSir((const complex **)z_sir, lungime_sir);
    printf("Sirul argumentelor elementelor sirului de nr complexe:\n");
    for (int i = 0; i < lungime_sir; i++)
    {
        printf("%lf ", *(argumenteNrComplexe + i));
    }
    printf("\n");

#pragma region cleanup
    dealocare((complex ***)&z_sir, lungime_sir);
    free(s_par);
    s_par = NULL;
    free(s_impar);
    s_impar = NULL;
    free(s_total);
    s_total = NULL;
    free(sir_module);
    sir_module = NULL;
    free(argumenteNrComplexe);
    argumenteNrComplexe = NULL;
#pragma endregion
    return EXIT_SUCCESS;
}