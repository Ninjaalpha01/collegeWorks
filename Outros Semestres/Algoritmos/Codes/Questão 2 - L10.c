#include <stdio.h>
#include <time.h>
#define lin 7
#define col 5

/*
void soma = função que soma os elementos de cada linha;
A[lin][col] = matriz do exercício;
V[lin] = vetor que cada indice representa a soma de cada linha da matriz;
c = controlador do menu;
i = variavel que representa a linha da matriz;
j = variavel que representa a coluna da matriz;
OBS: Para digitar os valores da matriz tirar do comentário linha 44 e 45
e colocar em comentário as linhas 46 e 47;
*/

void soma(int A[lin][col], int V[]);

int main()
{
	srand(time(NULL));
	int c=1, i=0, j, opc;
	int A[lin][col], V[lin]={0};
	
	do
	{
		printf("Insira uma opcao:\n");
		printf("1 - Somatoria das linhas de uma matriz\n");
		printf("2 - Quit\n");
		scanf("%d", &opc);
		system("cls");
		
		switch (opc)
		{
			case 1:
				{
					printf("Insira os valores da matriz:\n");
					
					while (i < lin)
					{
						j = 0;
						while (j < col)
						{
							//printf("[%d][%d]: ", i, j);
							//scanf("%f", &A[i][j]);
							A[i][j] = rand()%50;
							printf("[%d][%d]: %d\n", i, j, A[i][j]);
							j++;
						}
						i++;
					}
					
					system("pause");
					soma (A,V);
					
					printf("Somatoria das linhas:\n");
					i = 0;
					while (i < lin)
					{
						printf("Linha %d: %d\n", i, V[i]);
						i++;
					}
					
					system("pause");
					system("cls");
				}
				break;
				
			case 2:
				{
					printf("Ate mais!\n");
					c = 0;
				}
				break;
				
			default:
				printf("Opcao invalida. Tente novamente\n");
		}
	} while (c == 1);
	return 0;
}

void soma(int A[lin][col], int V[])
{
	int i, j=0;
	
	i = 0;
	while (i < lin)
	{
		j = 0;
		while (j < col)
		{
			printf("eai\n");
			V[i] = V[i]+A[i][j];
			j++;
		}
		i++;
	}
}
