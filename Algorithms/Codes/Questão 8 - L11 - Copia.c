#include <stdio.h>
#include <time.h>

int pesquisa(int vet[], int n, int k);

int main()
{
	srand(time(NULL));
	int i, k, pos, n=10;
	int vet[n];
	
	for (i=0; i < n; i++)
	{
		vet[i] = rand()%10;
		printf("[%d]: %d\n", i, vet[i]);
	}
	
	printf("Insira o elemento k: ");
	scanf("%d", &k);
	
	pos = pesquisa(vet,n,k);
	
	printf("A posicao que se encontra o elemento eh a %da", pos);
	
	return 0;
}

int pesquisa(int vet[], int n, int k)
{
	if (n < 0)
		return -1;
	else
		{
			if (k == vet[n])
				{
					printf("isso\n");
					return n;
				}
			else
				return pesquisa(vet,n-1,k);
		}
}
