#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *aloca(int n);
float *uniao(float *v1, float *v2, int n1, int n2);
void desalocaf(float **v);

void main()
{
	int i, n1, n2;
	float *B=NULL, *A=NULL, *conc=NULL;
	
	printf("Insira o tamanho do vetor 1: ");
	scanf("%d", &n1);
	A = aloca(n1);
	printf("Insira o tamanho do vetor 2: ");
	scanf("%d", &n2);
	B = aloca(n2);
	
	conc = uniao(A,B,n1,n2);
	printf("Uniao dos vetores:\n");
	for (i=0; i<(n1+n2); i++)
		printf("%.2f ", *(conc+i));
	
	desalocaf(&A);
	desalocaf(&B);
	if (A==NULL && B==NULL)
		printf("\nMemoria livre!\n");
}

float *aloca(int n)
{
	srand(time(NULL));
	int i;
	float *p=NULL;
	
	p = (float *)malloc(n * sizeof(float));
	if (p)
	{
		printf("Insira os valores:\n");
		for (i=0; i<n; i++)
		{
			printf("[%d]: ", i+1);
			scanf("%f", (p+i));
			//*(p+i) = rand()%25;
			//printf("[%d]: %f\n", i+1, *(p+i));
		}
		
		return p;
	}
}

float *uniao(float *v1, float *v2, int n1, int n2)
{
	int i, j;
	float *p=NULL;
	
	p = (float *)malloc((n1+n2) * sizeof(float));
	if(p)
	{
		for (i=0; i<n1; i++)
			*(p+i) = *(v1+i);
		j = i;
		
		for (i=0; i<n2; i++, j++)
			*(p+j) = *(v2+i);
			
		return p;
	}
}

void desalocaf(float **v)
{
	free(*v);
	*v = NULL;
}
