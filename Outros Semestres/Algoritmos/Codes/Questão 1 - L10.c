#include <stdio.h>
#include <time.h> //Para usar a função srand
#define tam 5

//Para executar escolhendo os valores das matrizes, tirar comentarios da linha 32 e 33
//e colocar comentarios na liinha 34 e 35

//void separa(int mat[tam][tam], int vetse[tam]);
void diagonalSec(int matriz[5][5],int n);

int main()
{
	int c=1, i, j, opc;
	srand(time(NULL)); //declara que irei usar um numero randomico
	int mat[tam][tam], vetse[tam];
	
	do
	{
		printf("Insira uma opcao:\n");
		printf("1 - Separar os elementos da diagonal principal\n");
		printf("2 - Quit\n");
		scanf("%d", &opc);
		system("cls");
		
		switch (opc)
		{
			case 1:
				{
					printf("Insira os valores da matriz:\n");
					for (i=0; i < tam; i++)
						for (j=0; j < tam; j++)
						{
							printf("[%d][%d]: ", i+1, j+1);
							scanf("%d", &mat[i][j]);
							//mat[i][j] = rand()%10;
							//printf("[%d][%d]: %d\n", i+1, j+1, mat[i][j]);
						}
					
					system("pause");
					system("cls");
					
					printf("\nComposicao da matriz:\n");
					for (i=0; i < tam; i++)
					{
						printf("\n");
						for (j=0; j < tam; j++)
							printf("%d   ", mat[i][j]);
					}
					printf("\n\n");
					diagonalSec(mat,5);
					
					/*separa(mat,vetse);
					printf("O vetor referente a diagonal secundaria da matriz:\n");
					for (i=0; i < tam; i++)
						printf("[%d]: %d\n", i+1, vetse[i]);
					*/
					
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
				printf("Opcao invalida.\n");
		}
	} while (c == 1);
}

/* feita antes de tentar a atividade no coderunner
void separa(int mat[tam][tam], int vetse[tam])
{
	int i, j, k=0;
	
	for (i=0; i < tam; i++)
		for (j=0; j < tam; j++)
		{
			if (i+j+1 == tam)
			{
				vetse[k] = mat[i][j];
				k++;
			}
		}
}*/

void diagonalSec(int matriz[5][5],int n)
{
	int i, j, k=0;
	int vet[n];
	
	for (i=0; i < n; i++)
		for (j=0; j < n; j++)
		{
			if (i+j+1 == n)
			{
				vet[k] = matriz[i][j];
				k++;
			}
		}
	for (i=0; i < n; i++)
	    printf("[%d]%d\n", i, vet[i]);
}
