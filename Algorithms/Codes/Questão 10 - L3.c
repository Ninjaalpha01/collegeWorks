#include <stdio.h>

int main()
{
	int x1, x2, x3, x4;
	
	printf("Escolha entre:\n");
	printf("1 - mamiferos \n2 - aves\n");
	scanf("%i", &x1);
	
	switch (x1)
	{
		case 1:
			{
				printf("Escolha entre:\n");
				printf("1 - quadrupede \n2 - bipede\n");
				scanf("%i", &x2);
				
				switch (x2)
				{
					case 1:
						{
							printf("Escolha entre:\n");
							printf("1 - carnivoro \n2 - herbivoro\n");
							scanf("%i", &x3);
							
							switch (x3)
							{
								case 1:
									printf("Leao");
									break;
								case 2:
									printf("Cavalo");
									break;
								default:
									printf("Erro");
									break;
							}
						}
						break;
					case 2:
						{
							printf("Escolha entre:\n");
							printf("1 - onivoro \n2 - frutifero\n");
							scanf("%i", &x3);
							
							switch (x3)
							{
								case 1:
									printf("Homem");
									break;
								case 2:
									printf("Macaco");
									break;
								default:
									printf("Erro");
									break;
							}
						}
						break;
					default:
						printf("Erro");
						break;
				}
			}
			break;
		case 2:
			{
				printf("Escolha entre:\n");
				printf("1 - nao-voadoras \n2 - nadadoras\n");
				scanf("%i", &x2);
				
				switch (x2)
				{
					case 1:
						printf("Escolha entre:\n");
						printf("1 - tropical \n2 - polar\n");
						scanf("%i", &x3);
						
						switch (x3)
						{
							case 1:
								printf("Avestruz");
								break;
							case 2:
								printf("Pinguim");
								break;
							default:
								printf("Erro");
								break;
						}
						break;
					case 2:
						printf("Pato");
						break;
					default:
						printf("Erro");
						break;
				}
			}
			break;
		default:
			printf("Erro");
			break;
	}
}
