#include <stdio.h>
#include <math.h>
#define pi 3.1416

void tri(float b, float h)
{
	float area;
	area = b*h/2;
	printf("A area do triangulo equivale a: %.2f\n\n", area);
}

void cir(float r)
{
	float area;
	area = pi*(pow(r,2));
	printf("A area do circulo equivale a: %.2f\n\n", area);
}

void cub(float l)
{
	float vol;
	vol = pow(l,3);
	printf("O volume do cubo equivale a: %.2f\n\n", vol);
}

void cil(float r, float h)
{
	float vol;
	vol = (pi*pow(r,2))*h;
	printf("O volume do cilindro equivale a: %.2f\n\n", vol);
}

void main()
{
	int opc, i=1;
	float a, b, c, d;
	//a = base, b = altura, c = raio
	
	do
	{
		printf("O que voce deseja calcular?\n");
		printf("1 - Area de um triangulo\n");
		printf("2 - Area de um circulo\n");
		printf("3 - Volume de um cubo\n");
		printf("4 - Volume de um cilindro\n");
		scanf("%d", &opc);
		
		switch (opc)
		{
			case 1:
				{
					printf("Insira o valor da base: ");
					scanf("%f", &a);
					printf("Insira o valor da altura:");
					scanf("%f", &b);
					
					tri(a,b);
				} break;
			case 2:
				{
					printf("Insira o valor do raio: ");
					scanf("%f", &c);
					
					cir(c);
				} break;
			case 3:
				{
					printf("Insira o valor de uma aresta: ");
					scanf("%f", &a);
					
					cub(a);
				} break;
			case 4:
				{
					printf("Insira o valor do raio: ");
					scanf("%f", &c);
					printf("Insira o valor da altura: ");
					scanf("%f", &b);
					
					cil(c,b);
				} break;
			case 5:
				printf("Obrigado por usar o algoritmo!\n"); i = 0;
				break;
			default:
				printf("Erro.\n"); i = 1;
				break;
		}
	} while (i == 1);
}
