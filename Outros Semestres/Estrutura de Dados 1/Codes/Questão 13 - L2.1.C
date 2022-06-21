#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void leitura(unsigned int*, int);
unsigned int *separa(unsigned int*, int);
unsigned int *alocaveti(int);
void imprimevi(unsigned int *, unsigned int*);

int main()
{
	int i, tam, np=0;
	
	printf("Qual o tamanho do vetor? ");
	scanf("%d", &tam);
	
	unsigned int *vet=NULL, **geral=NULL;
	vet = alocaveti(tam);
	
	leitura(vet,tam);
	
	*geral = separa(vet,tam);
	
	printf("par: ");
	//imprimevi(geral,(geral+1));
	for (i=0; i<*(geral+1); i++)
		printf("[%d]: %d\n", i, **(geral+i));
	printf("\nimpar: ");
	//imprimevi((geral+2),(geral+3));
	
	return 0;
}

void leitura(unsigned int *v, int n)
{
	srand(time(NULL));
	int i;
	
	printf("Insira os valores:\n");
	for (i=0; i<n; i++)
	{
		//printf("[%d]: ", i);
		//scanf("%d", (v+i));
		*(v+i) = rand()%35;
		printf("[%d]: %d", i, *(v+i));
	}
}

unsigned int *separa(unsigned int *v, int tam)
{
	int i, j=0, np=0, ni=0;
	
	for (i=0; i<tam; i++)
	{
		if (*(v+i)%2 == 0)
			np++;
		else
			ni++;
	}
	
	unsigned int *geral, *imp, *par;
	
	geral = (unsigned int*)malloc(4 * sizeof(unsigned int));
	par = alocaveti(np);
	imp = alocaveti(ni);
	
	for (i=0; i<tam; i++)
		if (*(v+i)%2 == 0)
		{
			*(v+i) = *(par+j);
			j++;
		}
	
	j = 0;
	for (i=0; i<tam; i++)
		if (*(v+i)%2 != 0)
		{
			*(v+i) = *(imp+j);
			j++;
		}
	
	*geral = *par;
	*(geral+1) = np;
	*(geral+2) = *imp;
	*(geral+3) = ni;
	
	return geral;
}

unsigned int *alocaveti(int tam)
{
	unsigned int *p=NULL;
	p = (unsigned int *)malloc(tam * sizeof(unsigned int));
	if(p==NULL)
		printf("\nSO nao liberou memoria!");
    return p; 
}

void imprimevi(unsigned int *vet, unsigned int *tam)
{
	int i;
	if(vet)
	{
		for(i=0; i<*tam; i++)
		   printf("%d ", *(vet+i));
		   printf("\n");
	}
	else printf("nao tem nada na memoria!");
}
