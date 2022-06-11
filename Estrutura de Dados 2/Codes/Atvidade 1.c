#include <stdlib.h>
#include <stdio.h>

struct TNoABP
{
	int chave;
	struct TNoABP *esq;
	struct TNoABP *dir;
} typedef TNoABP;


TNoABP *insereABP(TNoABP **r, int key)
{
	TNoABP *novo = NULL, *aux = *r, *ant = *r;
	
	novo = (TNoABP *)malloc(sizeof(TNoABP));
	
	if (novo == NULL)
		return NULL;
	
	novo->chave = key;
	novo->esq = NULL;
	novo->dir = NULL;
	
	if (*r == NULL)
		*r = novo;
	else
	{
		while (aux != NULL)
		{
			if (key <= aux->chave)
			{
				ant = aux;
				aux = aux->esq;
				if (aux != NULL && key > aux->chave)
				{
					novo->esq = aux;
					ant->esq = novo;
					return novo;
				}
			}
			else
				if (key > aux->chave)
				{
					ant = aux;
					aux = aux->dir;
					if (aux != NULL && key < aux->chave)
					{
						novo->dir = aux;
						ant->dir = novo;
						return novo;
					}
				}
		}
		if (key <= ant->chave)
			ant->esq = novo;
		else
			ant->dir = novo;
	}
	
	return novo;
}

void printABP(TNoABP *raiz)
{
	if (raiz==NULL)
		return;
	
	printABP(raiz->esq);
	printf("%d\n", raiz->chave);
	printABP(raiz->dir);
}   

int main()
{
	TNoABP *raiz = NULL;
	int key, i, tam;
	
	scanf("%d", &tam);

	for (i=0; i<tam; i++)
	{
		scanf("%d", &key);
		insereABP(&raiz,key);
	}
	
	printABP(raiz);
	
	return 0;
}
