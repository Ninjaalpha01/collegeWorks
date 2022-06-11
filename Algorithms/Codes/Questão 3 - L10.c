#include <stdio.h>
#include <time.h>
#define lin 7
#define col 5

void maior(int B[lin][col], int vet[]);

int main()
{
	srand(time(NULL));
	int c=1, i, j, opc;
	int B[lin][col], vet[3];
	
	do
	{
		printf("Insira uma opcao:\n");
		printf("1 - Encontrar o maior elemento numa matriz\n");
		printf("2 - Quit\n");
		scanf("%d", &opc);
		system("cls");
		
		switch (opc)
		{
			case 1:
				{
					printf("Insira os valores da matriz:\n");
					
					for (i=0; i < lin; i++)
						for (j=0; j < col; j++)
						{
							//printf("[%d][%d]:\t", i, j);
							//scanf("%f", &B[i][j]);
							B[i][j] = rand()%500;
							printf("[%d][%d]: %d\n", i, j, B[i][j]);
						}
					maior(B,vet);
					
					printf("O maior elemento e: [%d][%d] = %d\n", vet[1], vet[1], vet[0]);
					
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

void maior(int B[lin][col], int vet[3])
{
	int i, j;
	vet[0] = B[0][0];
	for (i=0; i < lin; i++)
		for (j=0; j < col; j++)
			if (B[i][j] >= vet[0])
				{
					vet[0] = B[i][j];
					vet[1] = i;
					vet[2] = j;
				}
}
