#include <stdio.h>

void result(int F[], const tam);

int main()
{
	const tam = 20;
	int i, c = 1;
	int F[tam], opc;
	
	do
	{
		system("cls");
		printf("Insira uma opcao:\n");
		printf("1 - Multiplicar cada elemento por sua posicao \n2 - Quit\n");
		scanf("%d", &opc);
		system("cls");
		
		switch (opc)
		{
			case 1:
				{
					printf("Insira:\n");
					for (i=0; i < tam; i++)
					{
						printf("%d numero: ", i+1);
						scanf("%d", &F[i]);
						system("cls");
					}
					
					result(F,tam);
					
					for (i=0; i < tam; i++)
					{
						if (i < 10)
							printf("F[%d]:%10d\n", i, F[i]);
						
						else
							printf("F[%d]:%9d\n", i, F[i]);
					}
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
				printf("Opcao invalida! Tente novamente.\n");
		}
		
	} while (c == 1);
	
	return 0;
}

void result(int F[], const tam)
{
	int i;
	for (i=0; i < tam; i++)
		F[i] = F[i]*i;
}
