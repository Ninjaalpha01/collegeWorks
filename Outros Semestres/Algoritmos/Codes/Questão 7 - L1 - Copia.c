#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main()
{
    /* a = area,
    com = comprimento,
    lar = largura,
    pot_i = potencia de iluminação,
    pot = potencia necessaria para cada m2.
    */

    float a, com, lar;
    int pot_i;
    const int pot=18;

    printf("Insira o comprimnto do comodo (em metros):\n");
    scanf("%f", &com);
    printf("Insira a largura do comodo (em metros):\n");
    scanf("%f", &lar);

    a = com*lar;
    pot_i = pot*a;

    printf("Area: %fm2 \n", a);
    printf("E necessario a luminacao de: %dW", pot_i);
}
