#include<stdio.h>
#include<stdlib.h>

int *aloca(int n);
void armazena(int *v, int n);
void imprime(int *v, int n);
int *concatena(int *a, int na, int *b, int nb);
void desaloca(int **v);

int main()
{
	int *pa, *pb, na, nb, *pconc=NULL;
	printf("Informe tamanho A:");
	scanf("%d",&na);
	pa = aloca(na);
	printf("Informe tamanho B:");
	scanf("%d",&nb);
	pb = aloca(nb);
	armazena(pa, na);
	armazena(pb, nb);
	printf("\nVetor A:");
	imprime(pa, na);
	printf("\nVetor B:");
	imprime(pb, nb);
	pconc = concatena(pa, na, pb, nb);
	desaloca(&pa);
	desaloca(&pb);
	printf("\nVetor C:");
	imprime(pconc, na+nb);
	desaloca(&pconc);
	printf("\n");
	imprime(pconc, na+nb);
	
}

int *aloca(int n)
{
	int *p=NULL;
	p = (int *)malloc(n * sizeof(int));
	if(p==NULL) printf("\nSO n?o liberou memoria!");
    return p; 
}

void armazena(int *v, int n)
{
	int i;
	if(v)
	{
		for(i=0; i<n; i++)
		{
		  printf("\nDigite valor [%d]=",i);
		  scanf("%d",(v+i));
		}
		   	
	}
	else printf("nao tem espaco na memoria!");
}

void imprime(int *vet, int tam)
{
   int i;
	if(vet)
	{
		for(i=0; i<tam; i++)
		   printf("%d ", *(vet+i));	
	}
	else printf("nao tem nada na memoria!");
}

int *concatena(int *a, int na, int *b, int nb)
{
	int *p,i,j=na;
	
	if(a && b)
	{
		//p = (int *)malloc((na+nb)*sizeof(int));	
		p = aloca(na+nb);
		if(p)
		{
			for(i=0;i<na;i++)
		    	*(p+i) = *(a+i);
		    j = na;
			for(i=0;i<nb;i++)
			{
			  *(p+j) = *(b+i);
			  j++;
			}
			return p;
		}
	}
}	

void desaloca(int **v)
{
	free(*v);
	*v=NULL;
}
