#include <stdio.h>
#include <time.h>

int sime(int n, int mat[n][n]);

int main()
{
	srand(time(NULL));
	int c=1, i, j, n, opc, res;
	
	do
	{
		printf("Insira uma opcao:\n");
		printf("1 - Verificar se a matriz e simetrica\n");
		printf("2 - Quit\n");
		scanf("%d", &opc);
		system("cls");
		
		switch (opc)
		{
			case 1:
				{
					printf("Insira a ordem da matriz: ");
					scanf("%d", &n);
					int mat[n][n];
					printf("Insira os valores da matriz:\n");
					
					for (i=0; i < n; i++)
						for (j=0; j < n; j++)
						{
							//printf("[%d][%d]:\t", i, j);
							//scanf("%d", &mat[i][j]);
							mat[i][j] = rand()%10;
							printf("[%d][%d]: %d\n", i, j, mat[i][j]);
						}
					
					system("cls");
					res = sime(n,mat);
					
					printf("\nComposicao da matriz:\n");
					for (i=0; i < n; i++)
					{
						printf("\n");
						for (j=0; j < n; j++)
							printf("%d   ", mat[i][j]);
					}
					printf("\n\n");
					if (res == 1)
						printf("A matriz eh simetrica!\n\n");
					else
						printf("A matriz nao eh simetrica!\n\n");
					
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

int sime(int n, int mat[n][n])
{
	int res=0, i=0, j=0;
	
	printf("Comparando\n");
	for (i=0; i < n; i++)
		for (j=0; j < n; j++)
		{
			printf("[%d][%d]: %d\t[%d][%d]: %d\n", i, j, mat[i][j], j, i, mat[j][i]);
			if (mat[i][j] == mat[j][i])
					res += 1;
		}
	if (res == (n*n))
		res = 1;
	else
		res = 0;
		
	return res;
}
