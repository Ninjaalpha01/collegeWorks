#include <stdio.h>
#define tam 5

void soma(int vet1[], int vet2[], int vetso[]);
void subt(int vet1[], int vet2[], int vetsu[]);
void mult(int vet1[], int vet2[], int vetmu[]);
void divi(int vet1[], int vet2[], float vetdi[]);

int main()
{
	int c=1, i, opc;
	int vet1[tam], vet2[tam], vetso[tam], vetsu[tam], vetmu[tam];
	float vetdi[tam];
	
	do
	{
		printf("Insira uma opcao:\n");
		printf("1 - Efetuar as operacoes\n");
		printf("2 - Quit\n");
		scanf("%d", &opc);
		system("cls");
		
		switch (opc)
		{
			case 1:
				{
					printf("Insira os valores do 1 vetor:\n");
					for (i=0; i < tam; i++)
						scanf("%d", &vet1[i]);
					printf("Insira os valores do 2 vetor:\n");
					for (i=0; i < tam; i++)
						scanf("%d", &vet2[i]);
					
					soma(vet1,vet2,vetso);
					
					printf("Soma dos elementos de cada vetor:\n");
					for (i=0; i < tam; i++)
						printf("vet[%d]: %d\n", i, vetso[i]);
					
					subt(vet1,vet2,vetsu);
					
					printf("Diferenca dos elementos de cada vetor:\n");
					for (i=0; i < tam; i++)
						printf("vet[%d]: %d\n", i, vetsu[i]);
					
					mult(vet1,vet2,vetmu);
					
					printf("Produto dos elementos de cada vetor:\n");
					for (i=0; i < tam; i++)
						printf("vet[%d]: %d\n", i, vetmu[i]);
					
					divi(vet1,vet2,vetdi);
					
					printf("Divisao entre os elementos de cada vetor:\n");
					for (i=0; i < tam; i++)
						printf("vet[%d]: %.2f\n", i, vetdi[i]);
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

void soma(int vet1[], int vet2[], int vetso[])
{
	int i;
	for (i=0; i < tam; i++)
		vetso[i] = vet1[i]+vet2[i];
}

void subt(int vet1[], int vet2[], int vetsu[])
{
	int i;
	for (i=0; i < tam; i++)
		vetsu[i] = vet1[i]-vet2[i];
}

void mult(int vet1[], int vet2[], int vetmu[])
{
	int i;
	for (i=0; i < tam; i++)
		vetmu[i] = vet1[i]*vet2[i];
}

void divi(int vet1[], int vet2[], float vetdi[])
{
	int i;
	for (i=0; i < tam; i++)
	{	
		if (vet2[i] != 0)
			vetdi[i] = (float)vet1[i]/vet2[i];
		else
			vetdi[i] = 0;
	}
}
