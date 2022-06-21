#include <stdio.h>
#include <stdlib.h>

double* max(double* a, int size);

void main()
{
	int tam = 3, i;
	double vet[tam];
	double *p=NULL;
	
	p = vet;
	
	printf("Preencha o vetor:\n");
	for (i=0; i<tam; i++)
	{
		printf("[%d]: ", i);
		scanf("%lf", &*(p+i));
	}
	
	p = max(vet,tam);
	
	if (p != NULL)
	{
		printf("\n%x\n", p);
		printf("%lf\n", *p);
	}
	else
		printf("\nNULL");
}

double* max(double* a, int size)
{
	int i;
	double *p;
	
	p = a;
	
	for (i=0; i<size; i++)
		if (*(a+i) == 0 && i == size-1)
			return NULL;
	
	for (i=1; i<size; i++)
		if (*(a+i) >= *p)
			p = a+i;
	
	/*
	printf("endereco de p: %x\n", p);
	printf("conteudo de p: %lf\n", *p);
	
	printf("---FIM DA FUNCAO---\n");
	*/
	
	return p;
}
