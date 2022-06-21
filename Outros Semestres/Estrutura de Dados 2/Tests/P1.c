#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct TNoABP
{
	int chave;
	struct TNoABP *esq;
	struct TNoABP *dir;
} typedef TNoABP;

TNoABP *insereABP(TNoABP **r, int key);
TNoABP **buscaABP(TNoABP **raiz, int key);
TNoABP **ppMenor(TNoABP **sub);
void removeNoABP(TNoABP **raiz, int key);
void ordem(TNoABP *raiz);
void substituiDados(TNoABP **orig, TNoABP **sub);

int main()
{
	int n, k, i;
	TNoABP *raiz = NULL;
	
	// a
	scanf("%d", &n);
	
	if (n <= 0)
		return 0;
	
	// b
	for (i=1; i <= n; i++)
	{
		scanf("%d", &k);
		insereABP(&raiz,k);
	}
	
	// c
	scanf("%d", &k);
	
	// d
	removeNoABP(&raiz,k);
	
	// e
	ordem(raiz);
	
	return 0;
}

TNoABP *insereABP(TNoABP **r, int key)
{
	TNoABP *novo = NULL;
	
	novo = (TNoABP *)malloc(sizeof(TNoABP));
	
	if (novo == NULL)
		return NULL;
	
	novo->chave = key;
	novo->esq = NULL;
	novo->dir = NULL;
	
	if ((*r) == NULL)
	{
		*r = novo;
		return novo;
	}
	while ((*r)->esq != NULL || (*r)->dir != NULL)
	{
		if (key < (*r)->chave)
		{
			if ((*r)->esq == NULL)
			{
				(*r)->esq = novo;
				return novo;
			}
			r = &((*r)->esq);
		}
		else
			if (key > (*r)->chave)
			{
				if ((*r)->dir == NULL)
				{
					(*r)->dir = novo;
					return novo;
				}
				r = &((*r)->dir);
			}
	}
	if (key < (*r)->chave)
	{
		(*r)->esq = novo;
		return novo;
	}
	else
		if (key > (*r)->chave)
		{
			(*r)->dir = novo;
			return novo;
		}
	return NULL;
}

TNoABP **buscaABP(TNoABP **raiz, int key)
{
	assert(raiz);	
	
	if ((*raiz) == NULL)
		return NULL;
	
	if ((*raiz)->chave == key)
		return raiz;
	
	if (key > (*raiz)->chave)
		return buscaABP(&((*raiz)->dir),key);
	
	if (key < (*raiz)->chave)
		return buscaABP(&((*raiz)->esq),key);
	
	return NULL;
}

void removeNoABP(TNoABP **raiz, int key)
{
	TNoABP **pp = buscaABP(raiz,key);
	
	if (pp == NULL)
		return;
	
	if ((*pp)->esq == NULL && (*pp)->dir == NULL) //caso 1 - no folha
	{
		free(*pp);
		*pp = NULL;
		return;
	}
	else
		if (((*pp)->esq == NULL) != ((*pp)->dir == NULL)) //caso 2 - um filho
		{
			TNoABP *filho = NULL;
			
			if ((*pp)->esq != NULL)
				filho = (*pp)->esq;
			else
				filho = (*pp)->dir;
			
			free(*pp);
			*pp = filho;
			return;
		}
		else //caso 3 - dois filhos
		{
			TNoABP **pps = ppMenor(&((*pp)->dir));
			substituiDados(pp,pps);
			removeNoABP(pps,(*pps)->chave);
		}
}

TNoABP **ppMenor(TNoABP **sub)
{
	assert(sub);
	
	if ((*sub) == NULL)
		return NULL;
	
	if ((*sub)->esq == NULL)
		return sub;
	
	if ((*sub)->esq)
		return ppMenor(&((*sub)->esq));
	
	return NULL;
}

void substituiDados(TNoABP **orig, TNoABP **sub)
{
	(*orig)->chave = (*sub)->chave;
}

void ordem(TNoABP *raiz)
{
	if (!raiz)
		return;
	
	ordem(raiz->esq);
	printf("%d\n", raiz->chave);
	ordem(raiz->dir);
}
