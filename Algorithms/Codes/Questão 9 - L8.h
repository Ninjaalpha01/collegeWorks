#include <stdio.h>
#include <stdlib.h>

int hora(int hi, int hf)
{
	int total;
	
	if (hf < hi)
		hf += 24;
		
	total = hf-hi;
	return total;
}

int minu(int mi, int mf)
{
	int total;
	total = mf-mi;
	return total;
}

int teste(int x, int y)
{
	if (x < 0 || y < 0)
		return 1;
	else
		return 0;
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
