#include <stdio.h>
#include <time.h>
#define tam 10

void separaVetor(int vet[tam]);

int main()
{
	int vet[tam];
	int c=1, i, opc;
	
	do
	{
		system("cls");
		printf("Insira uma opcao:\n");
		printf("1 - Separar impares e pares \n2 - Quit\n");
		scanf("%d", &opc);
		system("cls");
		
		switch (opc)
		{
			case 1:
				{
					printf("Insira valores positivos no vetor:\n");
					for (i=0; i < tam; i++)
					{
						printf("vet[%d]: ", i);
						scanf("%d", &vet[i]);
						if (vet[i] < 0)
							i--;
					}
					system("cls");
					separaVetor(vet);
				}
				break;
				
			case 2:
				{
					printf("Ate mais!\n");
					c = 0;
				}
				break;
				
			default:
				printf("Erro. Opcao invalida\n");
		}
	} while (c == 1);
	
	return 0;
}

void separaVetor(int vetor[tam])
{
	int i, j=0, k=0, P[tam];
	
	for (i=0; i < tam; i++)
	{
		if (vetor[i]%2 == 0)
		{
			P[j] = vetor[i];
			j++;
			printf("isso");
		}
		else
			for(k=i; k > 0 && vetor[k]%2 == 0; k--)
			{
				printf("k = %d, i = %d, vetor[%d], vetor[%d]\n", k, i, k, i, vetor[k], vetor[i]);
				vetor[k] = vetor[i];
			}
	}
	printf("vetor[15]: ");
	for (i=0; i < tam; i++)
		printf("%d ", vetor[i]);
	system("pause");
}

/*void separavet(int vet[tam])
{
	int i, j=0, k=0, P[tam], I[tam];
	
	for (i=0; i < tam; i++)
	{
		if (vet[i]%2 == 0)
		{
			P[j] = vet[i];
			j++;
		}
		else
		{
			I[k] = vet[i];
			k++;
		}
	}
	printf("Impares:\n");				
	
	for (i=0; i < k; i++)
		printf("%d\n", I[i]);

	printf("Pares:\n");
		
	for (i=0; i < j; i++)
		printf("%d\n", P[i]);
	
	system("pause");
}*/
