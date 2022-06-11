#include <stdio.h>
#include <stdlib.h>

int anod(int a)
{
	int dias;
	dias = a*365;
	return dias;
}

int mesd(int m)
{
	int dias;
	dias = m*30;
	return dias;
}

int reset()
{
	int res;
RESET:
	fflush(stdin);
	printf("\nDeseja refazer o processo? (s/n)\n");
	scanf("%c", &res);
	
	switch (res)
	{
		case 's':
		case 'S':
			system("cls"); return res=1;
			break;
		
		case 'n':
		case 'N':
			printf("Ate mais!\n");
			break;
				
		default:
			printf("Opcao invalida.\n"); goto RESET;
			break;
	}
}
