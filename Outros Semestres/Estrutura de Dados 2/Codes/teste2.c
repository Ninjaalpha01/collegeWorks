#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct TNoAVL
{
	int chave;
	char fb;
	struct TNoAVL *esq;
	struct TNoAVL *dir;
} typedef TNoAVL;

void rotacaoDir(TNoAVL **raiz);
void rotacaoEsq(TNoAVL **raiz);
void preOrdem(TNoAVL *raiz);
char insereAVL(TNoAVL **raiz, int key);
TNoAVL **buscaPP(TNoAVL **raiz, int key);

int main()
{
	TNoAVL *raiz = NULL;
	
	insereAVL(&raiz,52);
	insereAVL(&raiz,22);
	insereAVL(&raiz,8);
	insereAVL(&raiz,2);
	insereAVL(&raiz,5);
	insereAVL(&raiz,7);
	insereAVL(&raiz,85);
	insereAVL(&raiz,96);
	insereAVL(&raiz,100);
	
	printf("Pre-Ordem:\n");
	preOrdem(raiz);
	
	return 0;
}

char insereAVL(TNoAVL **raiz, int key)
{
	TNoAVL *novo = NULL;
	char cresceu;
	
	novo = (TNoAVL *)malloc(sizeof(TNoAVL));
	
	if (novo == NULL)
	{
		printf("SO nao liberou memoria!\n");
		exit(0);
	}
	
	novo->chave = key;
	novo->esq = NULL;
	novo->dir = NULL;
	novo->fb = 0;
	
	if ((*raiz) == NULL)
	{
		*raiz = novo;
		return 1;
	}
	
	if (key < (*raiz)->chave)
	{
		cresceu = insereAVL(&((*raiz)->esq),key);
		
		if (cresceu)
		{
			switch ((*raiz)->fb)
			{
				case 0:
					{
						(*raiz)->fb = -1;
						return 1;
					} break;
					
				case -1:
					{
						(*raiz)->fb = -2;
						
						if ((*raiz)->esq->fb <= 0)
						{
							if ((*raiz)->dir)
								(*raiz)->fb = 1;
							else
								(*raiz)->fb = 0;
	
							rotacaoDir(raiz);
	
							(*raiz)->fb = 0;
						}
						else
						{
							if ((*raiz)->dir)
								(*raiz)->fb = 1;
							else
								(*raiz)->fb = 0;
	
							(*raiz)->esq->fb = 0;
	
							rotacaoEsq(&((*raiz)->esq));
							rotacaoDir(raiz);
	
							(*raiz)->fb = 0;
						}
						return 0;
					} break;
					
				case 1:
					{
						(*raiz)->fb = 0;
						return 0;
					} break;
			}
		}
	}
	else
		if (key > (*raiz)->chave)
		{
			cresceu = insereAVL(&((*raiz)->dir),key);
		
			if (cresceu)
			{
				switch ((*raiz)->fb)
				{
					case 0:
						{
							(*raiz)->fb = 1;
							return 1;
						} break;
					
					case -1:
						{
							(*raiz)->fb = 0;
							return 0;
						} break;
					
					case 1:
						{
							(*raiz)->fb = 2;
							if ((*raiz)->dir >= 0)
							{
								if ((*raiz)->esq)
									(*raiz)->fb = -1;
								else
									(*raiz)->fb = 0;
		
								rotacaoEsq(raiz);
								(*raiz)->fb = 0;
							}
							else
							{
								if ((*raiz)->esq)
									(*raiz)->fb = -1;
								else
									(*raiz)->fb = 0;
		
								(*raiz)->dir->fb = 0;
		
								rotacaoDir(&((*raiz)->dir));
								rotacaoEsq(raiz);
		
								(*raiz)->fb = 0;
							}
							return 0;
						} break;
				}
			}
		}
	return 0;
}

TNoAVL **buscaPP(TNoAVL **raiz, int key)
{
	assert(raiz);	
	
	if ((*raiz) == NULL)
		return NULL;
	
	if ((*raiz)->chave == key)
		return raiz;
	
	if (key > (*raiz)->chave)
		return buscaPP(&((*raiz)->dir),key);
		
	if (key < (*raiz)->chave)
		return buscaPP(&((*raiz)->esq),key);
		
	return NULL;
}

void rotacaoEsq(TNoAVL **raiz)
{
	TNoAVL *buf=*raiz, *buf2=NULL;
	
	(*raiz) = (*raiz)->dir;
	buf2 = (*raiz)->esq;
	(*raiz)->esq = buf;
	buf->dir = buf2;
	
	return;
}

void rotacaoDir(TNoAVL **raiz)
{
	TNoAVL *buf=*raiz, *buf2=NULL;
	
	(*raiz) = (*raiz)->esq;
	buf2 = (*raiz)->dir;
	(*raiz)->dir = buf;
	buf->esq = buf2;
	
	return;
}
void preOrdem(TNoAVL *raiz)
{
	if (!raiz)
		return;
	
	printf("%d\n", raiz->chave);
	preOrdem(raiz->esq);
	preOrdem(raiz->dir);
	
	return;
}
