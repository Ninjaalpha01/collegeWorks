#include <stdio.h>
#include "bibliot1.h"

int main()
{
	int opc, n, base, exp, ntermos, res, x = 1, i = 1;
	float med;
	
	do
	{
		system("cls");
		printf("Escolha uma operacao:\n");
		printf("1 - Fatorial \n2 - Potencia \n3 - Fibonacci \n4 - Media de Altura\n");
		printf("5 - Quit\n");
		scanf("%d", &opc);
		
		switch (opc)
		{
			case 1:
				{
					do
					{
						printf("\nInsira o valor: ");
						scanf("%d", &n);
						if (n >= 0)
						{
							res = Fatorial(n);
							printf("\nFatorial de %d equivale a: %d\n\n", n, res);
							x = 1;
						}
						else
						{
							printf("Valor invalido.\n");
							x = 0;
						}
					} while (x == 0);
					system("pause");
				}
				break;
			
			case 2:
				{
					printf("\nInsira o valor da base: ");
					scanf("%d", &base);
					printf("Insira o exponencial: ");
					scanf("%d", &exp);
					
					res = Potencia(base,exp);
					
					if (exp > 0)
						printf("\n%d elevado a %d eh igual a: %d\n\n", base, exp, res);
					
					else
						printf("\n%d elevado a %d eh igual a: 1/%d \n\n", base, exp, res);
									
					system("pause");
				}
				break;
				
			case 3:
				{
					do
					{
						printf("\nInsira o numero de termos: ");
						scanf("%d", &ntermos);
						if (ntermos >= 0)
						{
							res = SomaFibonacci(ntermos);
							printf("A soma eh igual a: %d\n\n", res);
							x = 1;
						}
						else
						{
							printf("Erro. Valor invalido.\n");
							x = 0;
						}
					} while (x == 0);
					system("pause");
				}
				break;
				
			case 4:
				{
					do
					{
						printf("\nInsira o quantos numeros compoem a media: ");
						scanf("%d", &n);
						if (n > 1)
						{
							med = MediaAltura(n);
							printf("A media eh igual a: %f\n\n", med);
							x = 1;
						}
						else
						{
							printf("Erro. Valor invalido.\n");
							x = 0;
						}
					} while (x == 0);
					system("pause");
				}
				break;
				
			case 5:
				{
					printf("Ate mais!\n\n");
					i = 0;
				}
				break;
			
			default:
				printf("Erro. Insira novamente.\n\n");
		}
	} while (i == 1);
	
	return 0;
}
