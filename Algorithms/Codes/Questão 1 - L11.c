#include <stdio.h>
#include <time.h>

int maior_elem(int A[], int n, int maior);

int main ()
{
	srand(time(NULL));
	int maior, c, i, n=15, opc;
	int A[n];
	
	do
	{
		printf("Insira os elementos do vetor:\n");
		for (i=0; i < n; i++)
		{
			//printf("[%d]: ", i);
			//scanf("%d", &A[i]);
			A[i] = rand()%1000;
			printf("[%d]: %d\n", i, A[i]);
		}
		maior = maior_elem(A,n,0);
		printf("O maior elemento do vetor eh: %d\n", maior);
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

int maior_elem(int A[], int n, int maior)
{
	if (n == 0)
		return maior;
	else
		if (maior < A[n])
			{
				maior = A[n];
				return maior_elem(A,n-1,maior);
			}
		else
			return maior_elem(A,n-1,maior);
}
