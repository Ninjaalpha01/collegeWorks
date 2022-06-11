#include <stdio.h>

int main ()
{
	int x;
	
	printf("Insira o codigo: ");
	scanf("%i", &x);
	
	switch (x)
	{
		case 1:
			printf("Grupo com 50%% de promocao");
			break;
		case 3:
		case 5:
			printf("Grupo sem desconto");
			break;
		case 10 ... 20:
			printf("Grupo com 10%% de desconto");
			break;
		default:
			printf("Codigo nao valido");
			break;
	}
}
