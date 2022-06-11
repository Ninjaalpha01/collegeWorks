#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main()
{
    float r, r1, v;
    const float pi=3.141592;

    printf("Insira o raio:\n");
    scanf("%f", &r);

    r1=pow(r,3);
    v=(pi*r1)*4/3;

    printf("O volume se define por:\n");
    printf("%f", v);
}
