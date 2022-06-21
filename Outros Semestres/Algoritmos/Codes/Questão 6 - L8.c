#include <stdio.h>

int pot(int a, int x);
int reset();

int main()
{
	int a, x, i, res;
	
	do
	{
		printf("Insira o valor da base: ");
		scanf("%d", &a);
		printf("Insira o valor do expoente: ");
		scanf("%d", &x);
		
		res = pot(a,x);
		
		printf("A potencia e igual a: %d\n", res);
		
		i = reset();
	} while (i == 1);
	
	return 0;
}

int pot(int a, int x)
{
	int p=1;
	
	for (x; x > 0; x--)
	{
		p *= a;
	}
	
	return p;
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
			return res=1;
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
