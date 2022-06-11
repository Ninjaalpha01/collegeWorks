#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mm(int *v, int n, int *pmin, int *pmax);

void main()
{
	srand(time(NULL));
	int tam, min, max;
	
	printf("Insira o tamanho do vetor: ");
	scanf("%d", &tam);
	
	int vet[tam], i;
	
	for (i=0; i<tam; i++)
	{
		*(vet+i) = rand()%100;
		printf("[%d]: %d\n", i, *(vet+i));
	}
	
	
	mm(vet,tam,&min,&max);
	
	printf("Maior elemento: %d\n", max);
	printf("Menor elemento: %d\n", min);
}

void mm(int *v, int n, int *pmin, int *pmax)
{
	int i;
	
	*pmin = *v;
	*pmax = *v;
	
	for (i=1; i<n; i++)
	{
		if (*pmin > *(v+i))
			*pmin = *(v+i);
		
		if (*pmax < *(v+i))
			*pmax = *(v+i);
	}
}
