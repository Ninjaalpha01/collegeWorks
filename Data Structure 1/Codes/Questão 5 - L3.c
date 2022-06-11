#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int coeficiente;
	int expoente;
	char incognita;
} Tipoexpr;

void insereexpr(Tipoexpr *v, int n);
Tipoexpr *simplifica(Tipoexpr *v, int n);

int main()
{
	int i, n;
	
	printf("Insira n: ");
	scanf("%d", &n);
	
	Tipoexpr expressao[n], *simp;
	
	insereexpr(expressao,n);
	
	for (i=0; i<n; i++)
	{
		printf("v[%d].incognita = %c\n", i, expressao[i].incognita);
		printf("v[%d].expoente = %d\n", i, expressao[i].expoente);
	}
	
	simp = simplifica(expressao,n);
	
	return 0;
}

void insereexpr(Tipoexpr *v, int n)
{
	int i;
	
	printf("Insira as expressoes:\n");
	
	for (i=0; i<n; i++)
	{
		printf("\nCoeficiente: ");
		scanf("%d", &v[i].coeficiente);
		fflush(stdin);
		printf("Incognita: ");
		scanf("%c", &v[i].incognita);
		fflush(stdin);
		printf("Expoente: ");
		scanf("%d", &v[i].expoente);
		fflush(stdin);
	}
}

Tipoexpr *simplifica(Tipoexpr *v, int n)
{
	int i=0, n1=1;
	Tipoexpr *p;
	
	p = (Tipoexpr *)malloc(sizeof(Tipoexpr));
	
	p->expoente = v[i].expoente;
	p->incognita = v[i].incognita;
	
	for (i=1; i<n; i++)
	{
		if (p->incognita==v[i].incognita)
		{
			printf("p1\n");
			printf("i = %d\n", i);
			printf("%c = %c\n", p->incognita, v[i].incognita);
			if(p->expoente != v[i].expoente)
			{
				printf("p2\n");
				printf("i = %d\n", i);
				printf("%d = %d\n", p->expoente, v[i].expoente);
				n1++;
				p->expoente = v[i].expoente;
				p->incognita = v[i].incognita;
			}
		}
	}
	printf("\n%d\n", n1);
	
	
	Tipoexpr *simp;
	
	
	return simp;
}
