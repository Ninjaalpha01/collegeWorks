#include <stdio.h>
#define tam 10

int func(int vet[tam], int nx);

int main()
{
	int i, c=1, c2=1, c3=1, opc, opc2, vet[tam], n;
	
	do
	{
		system("cls");
		printf("Insira uma opcao:\n");
		printf("1 - Quantas vezes um numero repete em um vetor \n2 - Quit\n");
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
						scanf("%d", &vet[i]);
						system("cls");
					}
					do
					{
						printf("Digite o numero que gostaria de verificar: ");
						scanf("%d", &n);
						
						n = func(vet,n);
						
						printf("O numero foi digitado %d vezes\n", n);
						printf("Deseja testar outro numero dentro desse vetor?(1-sim/2-nao)\n");
						scanf("%d", &opc2);
						
						switch (opc2)
						{
							case 1:
								c2 = 1;
								break;
								
							case 2:
								c2 = 0;
								break;
							
							default:
								printf("Opcao invalida.\n");
						}
						system("cls");
					} while (c2 == 1);
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
				printf("Opcao invalida, tente novamente\n");
				break;
		}
	} while (c == 1);
	
	return 0;
}

int func(int vet[], int n)
{
	int nx, i;
	for (i=0; i < tam; i++)
	{
		if (n == vet[i])
			nx++;
	}
	return nx;
}
