#include <stdio.h>
#define tam 15

int par(int vet[], int vetpar[]);

int main()
{
	int c=1, opc, i, j=15;
	int vet[tam], vetpar[j];
	
	do
	{
		system("cls");
		printf("Insria uma opcao:\n");
		printf("1 - Separar elementos pares dos impares \n2 - Quit\n");
		scanf("%d", &opc);
		system("cls");
		
		switch (opc)
		{
			case 1:
				{
					printf("Insira os valores:\n");
					for (i=0; i < tam; i++)
						scanf("%d", &vet[i]);
					system("cls");
					j = par(vet,vetpar);
					printf("Pares:\n");
					for (i=0; i < j; i++)
						printf("[%d]: %d\n", i, vetpar[i]);
					
					c = 1;
					system("pause");
				}
				break;
			
			case 2:
				{
					printf("Ate mais!\n");
					c = 0;
				}
				break;
			
			default:
				printf("Valor inserido invalido.\n");
		}
	} while (c == 1);
	return 0;
}

int par(int vet[], int vetpar[])
{
	int i=0, j=0;
	for (; i < tam; i++)
	{
		if (vet[i]%2 == 0)
		{
			vetpar[j] = vet[i];
			j++;
		}
	}
	return j;
}
