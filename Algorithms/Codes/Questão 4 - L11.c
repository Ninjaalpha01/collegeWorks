#include <stdio.h>
#include <time.h>

int multi(int V[], int n);

int main()
{
	srand(time(NULL));
	int i, c, opc, mul, n;
	
	do
	{
		do
		{
			printf("Insira o tamanho do Vetor: ");
			scanf("%d", &n);
		} while (n <= 0);
		
		int V[n];
		
		printf("Insira os valores do Vetor:\n");
		for (i=0; i < n; i++)
		{
			//printf("[%d]: ", i);
			//scanf("%d", &V[i]);
			V[i] = rand()%10;
			printf("[%d]: %d\n", i, V[i]);
		}
		
		mul = multi(V,n);
		
		printf("O resultado da multiplicacao eh de: %d\n\n", mul);
		
		printf("Voce deseja refazer? (1-sim/0-nao)\n");
		scanf("%d", &opc);
		if (opc == 1)
			{
				c = 1;
				system("cls");
			}
		else
			{
				printf("Ate mais!\n");
				c = 0;
			}
	} while (c == 1);
	return 0;
}

int multi(int V[], int n)
{
	if (n == 1)
		return V[0];
	else
		return V[n-1]*multi(V,n-1);
}
