#include <stdio.h>
#include <time.h>
#define tam 5

void SomaLin(int M[tam][tam], int SL[]);
void SomaCol(int M[tam][tam], int SC[]);

int main()
{
	srand(time(NULL));
	int c=1, i, j, opc;
	int M[tam][tam], SL[tam]={0}, SC[tam]={0};
	
	do
	{
		printf("Insira uma opcao:\n");
		printf("1 - Multiplicar a matriz por um valor\n");
		printf("2 - Quit\n");
		scanf("%d", &opc);
		system("cls");
		
		switch (opc)
		{
			case 1:
				{
				printf("Insira os valores da matriz M:\n");
				for (i=0; i < tam; i++)
					for(j=0; j < tam; j++)
					{
						//printf("[%d][%d]:\t", i, j);
						//scanf("%d", &M[i][j]);
						M[i][j] = rand()%10;
						printf("[%d][%d]: %d\n", i, j, M[i][j]);
					}
				system("pause");
				system("cls");
				printf("Composicao da matriz:\n");
				for (i=0; i < tam; i++)
				{
					printf("\n");
					for (j=0; j < tam; j++)
						printf("%d   ", M[i][j]);
				}
				printf("\n\n");
				
				SomaLin(M,SL);
				SomaCol(M,SC);
				
				printf("Soma das linhas:\n");
				for (i=0; i < tam; i++)
					printf("[%d]: %d\n", i, SL[i]);
				
				printf("Soma das colunas:\n");
				for (i=0; i < tam; i++)
					printf("[%d]: %d\n", i, SC[i]);
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
				printf("Opcao invalida. Tente novamente!\n");
		}
	} while (c == 1);
	
	return 0;
}

void SomaLin(int M[tam][tam], int SL[])
{
	int i, j, k=0;
	
	for (i=0; i < tam; i++)
	{
		for (j=0; j < tam; j++)
			SL[k] += M[i][j];
	k++;
	}
}

void SomaCol(int M[tam][tam], int SC[])
{
	int i, j, k=0;
	
	for (j=0; j < tam; j++)
	{
		for (i=0; i < tam; i++)
			SC[k] += M[i][j];
		k++;
	}
}
