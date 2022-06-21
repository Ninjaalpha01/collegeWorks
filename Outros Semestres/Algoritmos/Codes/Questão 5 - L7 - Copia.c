#include <stdio.h>

void soma(float a1, float r);
int reset();

void main()
{
	float x, y;
	
	do
	{
		printf("Insira o primeiro termo da PA:\n");
		scanf("%f", &x);
		printf("Insira a razao da PA:\n");
		scanf("%f", &y);
		
		soma(x,y);
	} while (reset() == 1);
}

void soma(float a1, float r)
{
	float an, sn;
	int n=5;
	
	an = a1+(n-1)*r;
	sn = (a1+an)*n/2;
	
	printf("\nA soma dos primeiros %d termos eh igual a: %.2f\n", n, sn);
}

int reset()
{
	int res;
RESET:
	fflush(stdin);
	printf("\nDeseja refazer o processo? (s/n)\n");
	scanf("%c", &res);
	
	switch (res)
	{
		case 's':
		case 'S':
			return res=1;
			break;
		
		case 'n':
		case 'N':
			printf("Obrigado por usar o algoritmo!\n");
			break;
				
		default:
			printf("Opcao invalida.\n"); goto RESET;
			break;
	}
}
