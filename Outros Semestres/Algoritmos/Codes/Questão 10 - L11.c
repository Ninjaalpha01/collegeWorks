#include <stdio.h>
#include <math.h>

float somar(int n);

int main()
{
	float somatoria;
	int n, opc;
	
	do
	{
		system("cls");
		printf("Insira n: ");
		scanf("%d", &n);
		
		somatoria = somar(n);
		printf("O calculo eh igual a: %.3f\n\n", somatoria);
		
		printf("Deseja refazer? (1-sim/2-nao): ");
		scanf("%d", &opc);
	} while (opc == 1);
	
	return 0;
}

float somar(int n)
{
	float soma;
	
	if (n == 1)
		return 1.0/2;
	else
		{
			soma = (pow(n,2)+1)/(n+3);
			return soma+(somar(n-1));
		}
}
