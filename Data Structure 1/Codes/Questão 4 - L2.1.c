#include <stdio.h>
#include <stdlib.h>

int *fat(int x);
int *quad(int *b);
void desaloca(int **v);

int main()
{
	int a, b;
	int *pa=NULL, *pb=NULL;
	
	printf("Insira A: ");
	scanf("%d", &a);
	printf("Insira B: ");
	scanf("%d", &b);
	fflush(stdin);
	
	pa = quad(&a);
	pb = fat(b);
	
	printf("O quadrado de %d eh: %d\n", a, *pa);
	printf("O fatorial de %d eh: %d\n", b, *pb);
	
	desaloca(&pa);
	desaloca(&pb);
	
	printf("Memoria Livre!");
	
	return 0;
}

int *quad(int *x)
{
	int *p=NULL;
	
	p = (int *)malloc(sizeof(int));
	*p = *x*(*x);
	
	return p;
}

int *fat(int x)
{
	int *p=NULL;
	
	p = (int *)malloc(sizeof(int));
	
	if (p==NULL)
		printf("SO nao liberou memoria!\n");
	
	*p = 1;
	
	if (x > 0)
	{
		while (x > 0)
		{
			*p *= x;
			x -= 1;
		}
	}
	
	return p;
}

void desaloca(int **v)
{
	free(*v);
	*v=NULL;
}
