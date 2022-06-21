#include <stdio.h>
#include <math.h>
#define tam 40

float media(int vet[], int n);
float somatoria(int vet[], int n);
float resultado(int n, float soma);

int main()
{
	int vet[tam], i;
	int opc, c;
	float soma, var;
	
	do
	{
		system("cls");
		printf("Escolha uma operacao:\n");
		printf("1 - Variancia \n2 - Quit\n");
		scanf("%d", &opc);
		
		switch (opc)
		{
			case 1:
				{
					printf("Insira a quantidade de faltas:\n");
					for (i=1; i <= tam; i++)
					{
						printf("%d aluno: ", i);
						scanf("%d", &vet[i]);
						if (vet[i] < 0)
						{
							printf("Valor invalido\n");
							i--;
						}
					}
					
					i--;
					soma = somatoria(vet,i);
					var = resultado(i,soma);
					printf("A variancia eh de: %f\n", var);
					
					c = 1;
					system("pause");
				} 
				break;
			
			case 2:
				{
					printf("Ate mais!\n");
					c = 0;
				}
				break;
			
			default:
				printf("Erro. Insira novamente.\n\n");
		}
	} while (c == 1);
	
	return 0;
}

float media(int vet[], int i)
{
	int soma, n;
	float med;
	
	soma = 0;
	for (n=1; n <= i; n++)
		soma = soma+vet[n];
	
	med = (float)soma/(n-1);
	return med;
}

float somatoria(int vet[], int i)
{
	int n;
	float med, soma, res;
	
	soma = 0;
	med = media(vet,i);
	for (n=1; n <= i; n++)
	{
		res = vet[n]-med;
		soma = soma+pow(res,2);
	}
	
	return soma;
}

float resultado(int n, float soma)
{
	float res;
	res = (float)soma/n;
	return res;
}
