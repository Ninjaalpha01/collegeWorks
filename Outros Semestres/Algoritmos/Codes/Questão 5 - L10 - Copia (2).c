#include <stdio.h>
#include <time.h>
#define tam 5

int soma_lin4(int M[tam][tam]);
int soma_col2(int M[tam][tam]);
int soma_dpri(int M[tam][tam]);
int soma_dseg(int M[tam][tam]);
int soma_elem(int M[tam][tam]);
void calcularSomas(float matriz[5][5],int n);

int main()
{
	srand(time(NULL));
	int c=1, i, j, opc;
	float M[tam][tam], lin4, col2, dpri, dseg, elem;
	
	do
	{
		printf("Insira uma opcao:\n");
		printf("1 - Calcular somas\n");
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
							printf("[%d][%d]:\t", i, j);
							scanf("%f", &M[i][j]);
							//M[i][j] = rand()%10;
							//printf("[%d][%d]: %d\n", i, j, M[i][j]);
						}
					system("pause");
					system("cls");
					printf("Composicao da matriz:\n");
					for (i=0; i < tam; i++)
					{
						printf("\n");
						for (j=0; j < tam; j++)
							printf("%f   ", M[i][j]);
					}
					printf("\n\n");
					
					calcularSomas(M,5);
					
					/*
					lin4 = soma_lin4(M);
					col2 = soma_col2(M);
					dpri = soma_dpri(M);
					dseg = soma_dseg(M);
					elem = soma_elem(M);
					
					
					printf("Resultado das somas:\n");
					printf("Linha 4: %d\n", lin4);
					printf("Coluna 2: %d\n", col2);
					printf("Diagonal principal: %d\n", dpri);
					printf("Diagonal secundaria: %d\n", dseg);
					printf("Todos os elementos da matriz: %d\n\n", elem);
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
				printf("Opcao invalida. Tente novamente\n");
		}
	} while (c == 1);
	return 0;
}

void calcularSomas(float matriz[5][5],int n)
{
	int i, j;
	float lin4, col2, dpri, dseg, elem;
	
	for (j=0; j < n; j++)
		lin4 += matriz[3][j];
	
	for (i=0; i < n; i++)
		col2 += matriz[i][1];
		
	for (i=0; i < n; i++)
		for (j=0; j < n; j++)
			if (i == j)
				dpri += matriz[i][j];
	
	for (i=0; i < n; i++)
		for (j=0; j < n; j++)
			if (i+j+1 == n)
				dseg += matriz[i][j];
	
	for (i=0; i < n; i++)
		for (j=0; j < n; j++)
			elem += matriz[i][j];
	
	printf("%f %f %f %f %f\n", lin4, col2, dpri, dseg, elem);
}

/*
int soma_lin4(int M[tam][tam])
{
	int i, j, res=0;
	
	for (j=0; j < tam; j++)
		lin4 += M[3][j];
	
	return res;
}

int soma_col2(int M[tam][tam])
{
	int i, j, res=0;
	
	for (i=0; i < tam; i++)
		res += M[i][1];
		
	return res;
}

int soma_dpri(int M[tam][tam])
{
	int i, j, res=0;
	
	for (i=0; i < tam; i++)
		for (j=0; j < tam; j++)
			if (i == j)
				res += M[i][j];
	
	return res;
}

int soma_dseg(int M[tam][tam])
{
	int i, j, res=0;
	
	for (i=0; i < tam; i++)
		for (j=0; j < tam; j++)
			if (i+j+1 == tam)
				res += M[i][j];
				
	return res;
}

int soma_elem(int M[tam][tam])
{
	int i, j, res=0;
	
	for (i=0; i < tam; i++)
		for (j=0; j < tam; j++)
			res += M[i][j];
			
	return res;
}
*/
