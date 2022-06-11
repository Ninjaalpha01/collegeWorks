#include <stdio.h>
#include <time.h>
#define tam 6

void mult(int M[tam][tam],int V[], int A);

int main()
{
	int c=1, i, j, opc;
	int M[tam][tam], A, V[tam*tam];
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
					printf("\nInsira o valor para multiplicar os elementos: ");
					scanf("%d", &A);
					system("pause");
					system("cls");
					
					mult(M,V,A);
					printf("Vetor dos valores multiplicados:\n");
					for (i=0; i < tam*tam; i++)
						printf("[%d]: %d\n", i, V[i]);
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

void mult(int M[tam][tam],int V[], int A)
{
	int i, j, k=0;
	
	for (i=0; i < tam; i++)
		for (j=0; j < tam; j++)
			{
				V[k] = M[i][j]*A;
				k++;
			}
}
