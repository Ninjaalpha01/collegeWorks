#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main()
{
    float ki, kf, cc, dp, gc;

    printf("Insira sua quilometragem inicial:\n");
    scanf("%f", &ki);
    printf("Insira sua quilometragem final:\n");
    scanf("%f", &kf);
    printf("Insira o consumo de combustivel (em litros):\n");
    scanf("%f", &cc);

    dp = kf-ki;
    gc= dp/cc;

    printf("Seu automovel percorre %fKm/L", gc);
}
