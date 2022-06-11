#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main()
{
    const float gal_pL=4.54609;
    float gal, litros;

    printf("Insrira um numero para converter\n");
    scanf("%f", &gal);

    litros=gal*gal_pL;

    printf("Sua quantidade em litros:\n");
    printf("%f", litros);

return 0;
}
