#include <stdio.h>
#include <time.h>
#include <math.h>
#define m 4
#define n 3

void operacoes(int mato[m][n], float matp[m][n]);

int main()
{
	srand(time(NULL));
	int c=1, i, j, opc;
	int matriz_ori[m][n];
	float matriz_pro[m][n];
	
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
					for (i=0; i < m; i++)
						for(j=0; j < n; j++)
						{
							//printf("[%d][%d]:\t", i, j);
							//scanf("%d", &matriz_ori[i][j]);
							matriz_ori[i][j] = rand()%10;
							printf("[%d][%d]: %d\n", i, j, matriz_ori[i][j]);
						}
					system("pause");
					system("cls");
				
					printf("Matriz Lida:\n");
					for (i=0; i < m; i++)
					{
						printf("\n");
						for (j=0; j < n; j++)
							printf("%d   ", matriz_ori[i][j]);
					}
					printf("\n\n");
					
					operacoes(matriz_ori,matriz_pro);
					
					printf("Matriz Processada:\n");
					for (i=0; i < m; i++)
					{
						printf("\n");
						for (j=0; j < n; j++)
							printf("%.3f\t", matriz_pro[i][j]);
					}
					printf("\n\n");
					
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

void operacoes(int mato[m][n], float matp[m][n])
{
	int i, j;
	
	for (i=0; i < m; i++)
		for (j=0; j < n; j++)
		{
			matp[i][j] = mato[i][j];
			
			if(matp[i][j] == 0)
				matp[i][j] = 0;
			
			else
				if ((int)matp[i][j]%2 == 0)
					matp[i][j] = 1/(float)matp[i][j];
				
				else
					matp[i][j] = pow(matp[i][j],2);
		}
}
