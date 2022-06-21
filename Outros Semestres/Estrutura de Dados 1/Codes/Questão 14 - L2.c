#include <stdio.h>
#include <stdlib.h>

float perimetro(float *a, float *b);

void main()
{
	float P, b, h;
	
	printf("Insira a base: ");
	scanf("%f", &b);
	printf("Insira a altura: ");
	scanf("%f", &h);
	
	P = perimetro(&b,&h);
	b *= 2;
	h *= 2;
	
	printf("O perimetro e de: %.2f\n", P);
	printf("\nNovos valores:\n");
	printf("Base: %.2f \nAltura: %.2f", b, h);
}

float perimetro(float *a, float *b)
{
	return 2**a+2**b;
}
