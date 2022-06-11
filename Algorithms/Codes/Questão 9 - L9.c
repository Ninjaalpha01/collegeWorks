#include <stdio.h>

void achei(int vetor[], int n, int x)
{
	int i;
	
	for (i=0; i < n; i++)
	{
		if (vetor[i] == x)
			printf("%d ", i);
	}
}

int main ()
{
	int vetor[5], i;
	
	printf("Insira os valores do vetor:\n");
	for (i=0; i < 5; i++)
		scanf("%d", &vetor[i]);
	achei(vetor,5,6);
	system("pause");
}
