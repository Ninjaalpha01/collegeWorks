#include <stdio.h>
#include <math.h>

int main ()
{
	char op;
	float tri, cir, cub, cil;
	float b, h, c, r;
	const float pi = 3.14;
	
	printf("A - area de um triangulo \nB - area de um circulo \nC - volume de um cubo \nD - volume de um cilindro\n");
	printf("O que voce deseja calcular?\n");
	scanf("%s", &op);
	
	switch (op)
	{
		case 'A':
		case 'a':
			{
				printf("Insira o valor da base: ");
				scanf("%f", &b);
				printf("Insira o valor da altura: ");
				scanf("%f", &h);
				
				tri = b*h/2;
				
				printf("Area do triangulo eh: %.2f", tri);
			}
			break;
		case 'B':
		case 'b':
			{
				printf("Insira o valor do raio: ");
				scanf("%f", &r);
				
				cir = pi*pow(r,2);
				
				printf("Area do circulo eh: %.2f", cir);
			}
			break;
		case 'C':
		case 'c':
			{
				printf("Insira o valor de um lado: ");
				scanf("%f", &b);
				
				cub = pow(b,3);
				
				printf("Volume do cubo eh: %.2f", cub);
			}
			break;
		case 'D':
		case 'd':
			{
				printf("Insira o valor do raio: ");
				scanf("%f", &r);
				printf("Insira o valor da altura: ");
				scanf("%f", &h);
				
				cil = pi*pow(r,2)*h;
				
				printf(" do cilindro eh: %.2f", cil);
			}
			break;
		default:
			printf("Invalido!");
			break;
	}
}
