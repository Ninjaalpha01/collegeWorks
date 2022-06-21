#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct TNoABP
{
	int chave;
	struct TNoABP *esq;
	struct TNoABP *dir;
} typedef TNoABP;

TNoABP *insereABP(TNoABP **raiz, int key);
int nosFolha(TNoABP *raiz, int *x);

int main()
{
	int n, i, key, numfolha = 0;
	TNoABP *raiz = NULL;
	
	do
		scanf("%d", &n);
	while (n<=0);
	
	for (i=0; i<n; i++)
	{
		scanf("%d", &key);
		insereABP(&raiz,key);
	}
	
	numfolha = nosFolha(raiz,&numfolha);
	printf("%d",numfolha);
	
	return 0;
}

TNoABP *insereABP(TNoABP **raiz, int key)
{
	TNoABP *novo = NULL;
	
	novo = (TNoABP *)malloc(sizeof(TNoABP));
	
	if (novo == NULL)
		return NULL;
	
	novo->chave = key;
	novo->esq = NULL;
	novo->dir = NULL;
	
	if ((*raiz) == NULL)
	{
		*raiz = novo;
		return novo;
	}
	while ((*raiz)->esq != NULL || (*raiz)->dir != NULL)
	{
		if (key < (*raiz)->chave)
		{
			if ((*raiz)->esq == NULL)
			{
				(*raiz)->esq = novo;
				return novo;
			}
			raiz = &((*raiz)->esq);
		}
		else
			if (key > (*raiz)->chave)
			{
				if ((*raiz)->dir == NULL)
				{
					(*raiz)->dir = novo;
					return novo;
				}
				raiz = &((*raiz)->dir);
			}
	}
	if (key < (*raiz)->chave)
	{
		(*raiz)->esq = novo;
		return novo;
	}
	else
		if (key > (*raiz)->chave)
		{
			(*raiz)->dir = novo;
			return novo;
		}
	return NULL;
}

int nosFolha(TNoABP *raiz, int *x)
{
	if (!raiz)
		return 0;
	
	if (!raiz->esq && !raiz->dir)
		*x = *x+1;
	nosFolha(raiz->esq,x);
	nosFolha(raiz->dir,x);
	
	return *x;
}
