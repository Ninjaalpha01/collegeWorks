#include <stdio.h>
#include <math.h>

void x2(int x)
{
	int quadrado;
	quadrado = pow(x,2);
	printf("O quadrado do numero e: %d\n", quadrado);
}

void raiz3(int x)
{
	int raiz, i, j=0;
	
	for (i=1; pow(i,3) <= x; i++)
	{
		if (pow(i,3) == x)
			{
				raiz = i;
				j = 1;
				printf("A raiz cubica do numero e: %d\n", raiz);
			}
	}
	if (j == 0)
		printf("Impossivel calcular a raiz cubica de %d\n", x);
}

void raiz2(int x)
{
	int raiz, i, j=0 ;
	
	for (i=1; pow(i,2) <= x; i++)
	{
		if (pow(i,2) == x)
		{
			raiz = i;
			printf("A raiz quadrada do numero e: %d\n", raiz);
			j=1;
		}
	}
	if (j == 0)
		printf("Impossivel calcular a raiz quadrada de %d\n", x);
}

void x3(int x)
{
	int cubo;
	cubo = pow(x,3);
	printf("O cubo do numero e: %d\n", cubo);
}

void main()
{
	int a;
	
	do
	{
		printf("Insira um numero inteiro e positivo: ");
		scanf("%d", &a);
	} while (a <= 0);
	
	x2(a);
	raiz3(a);
	raiz2(a);
	x3(a);
}
