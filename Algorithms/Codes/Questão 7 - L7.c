#include <stdio.h>
#include <math.h>

int cem(int x);
int cinq(int x);
int vint(int x);
int dez(int x);
int cinc(int x);
int um(int x);
int reset();

int main()
{
	int valor;
	int n100, n50, n20, n10, n5, n1;

	do
	{
		printf("Para converter em notas, insira o valor em reais: \nR$");
		scanf("%d", &valor);
		printf("\n");
		
		n100 = cem(valor);
		n50 = cinq(n100);
		n20 = vint(n50);
		n10 = dez(n20);
		n5 = cinc(n10);
		n1 = um(n5);
	} while (reset() == 1);
	
	return 0;
}

int cem(int x)
{
	int notas = 0;
	
	while (x >= 100)
		{
			x = x-100;
			notas++;
		}
	printf("Notas de R$100: %d\n", notas);
	
	return x;
}

int cinq(int x)
{
	int notas = 0;
	
	while (x >= 50)
		{
			x = x-50;
			notas++;
		}
	printf("Notas de R$50: \t%d\n", notas);
	
	return x;
}

int vint(int x)
{
	int notas = 0;
	
	while (x >= 20)
		{
			x = x-20;
			notas++;
		}
	printf("Notas de R$20: \t%d\n", notas);
	
	return x;
}

int dez(int x)
{
	int notas = 0;
	
	while (x >= 10)
		{
			x = x-10;
			notas++;
		}
	printf("Notas de R$10: \t%d\n", notas);
	
	return x;
}

int cinc(int x)
{
	int notas = 0;
	
	while (x >= 5)
		{
			x = x-5;
			notas++;
		}
	printf("Notas de R$5: \t%d\n", notas);
	
	return x;
}

int um(int x)
{
	int notas = 0;
	
	while (x >= 1)
		{
			x = x-1;
			notas++;
		}
	printf("Notas de R$1: \t%d\n", notas);
	
	return x;
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
