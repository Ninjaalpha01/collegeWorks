#include <stdlib.h>
#include <stdio.h>

void main()
{
    int n, hr, min, seg, rhr, rmin, rseg;

    printf("Insira o valor em segundos: ");
    scanf("%d", &n);

    hr = n/3600;
    rhr = n%3600;
    min = rhr/60;
    seg = rhr%60;

    printf("%d segundos sao ", n);
    printf("%d horas, ", hr);
    printf("%d minutos e ", min);
    printf("%d segundos", seg);
}
