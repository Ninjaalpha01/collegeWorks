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

//int x;

void rotacaoDir(TNoAVL **raiz);
void rotacaoEsq(TNoAVL **raiz);
void preOrdem(TNoAVL *raiz);
char insereAVL(TNoAVL **raiz, int key);
char insereAVL2(TNoAVL **raiz, int key);
TNoAVL **buscaPP(TNoAVL **raiz, int key);

int main()
{
	TNoAVL *raiz = NULL;
	
	insereAVL2(&raiz,52);
	insereAVL2(&raiz,22);
	insereAVL2(&raiz,8);
	insereAVL2(&raiz,2);
	insereAVL2(&raiz,5);
	insereAVL2(&raiz,7);
	insereAVL2(&raiz,85);
	insereAVL2(&raiz,96);
	insereAVL2(&raiz,100);
	
	printf("Pre-Ordem:\n");
	preOrdem(raiz);
	
	return 0;
}

char insereAVL(TNoAVL **raiz, int key)
{
	TNoAVL *novo = NULL;
	
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
	
	//if ((*raiz) != NULL)
	//printf("Raiz: %d\n", (*raiz)->chave);
	//printf("Insercao: %d\n", key);
	
	if ((*raiz) == NULL)
	{
		*raiz = novo;
		//printf("Raiz: %d\n", (*raiz)->chave);
		//printf("-- Inserido: %d --\n", key);
		return 1;
	}
	
	char ant = (*raiz)->fb;
	
	if (key < (*raiz)->chave)
	{
		(*raiz)->fb -= insereAVL(&((*raiz)->esq),key);
		//x = insereAVL(&((*raiz)->esq),key);
		//(*raiz)->fb -= x;
		//printf("\n--- Retorno:%d raiz:%d fb:%d ---\n", x, (*raiz)->chave, (*raiz)->fb);
	}
	else
		if (key > (*raiz)->chave)
		{
			(*raiz)->fb += insereAVL(&((*raiz)->dir),key);
			//x = insereAVL(&((*raiz)->dir),key);
			//(*raiz)->fb += x;
			//printf("\n--- Retorno:%d raiz:%d fb:%d ---\n", x, (*raiz)->chave, (*raiz)->fb);
		}
	
	//printf("Switch\n");
	switch ((*raiz)->fb)
	{
		case 0:
		{
			//printf("Posicao %d\n", (*raiz)->chave);
			//printf("FB Real: %d\n", (*raiz)->fb);
			
			if (ant == 0)
				return 0;
			
			return 1;
		} break;
		
		case 1:
		case -1:
		{
			//printf("Posicao %d\n", (*raiz)->chave);
			//printf("FB Real: %d\n", (*raiz)->fb);
			if (ant == 0)
				return 1;
			
			return 0;
		} break;
		
		case 2:
		{
			//printf("Posicao %d\n", (*raiz)->chave);
			//printf("FB Real: %d\n", (*raiz)->fb);
			
			if ((*raiz)->dir->fb >= 0)
			{
				(*raiz)->fb -= 2;
				rotacaoEsq(raiz);
				(*raiz)->fb--;
				
				//printf("Rotacao Simples Esquerda\n");
				//printf("--- FBs ---\n%d\n", (*raiz)->esq->fb);
				//printf("%d\n%d\n------\n", (*raiz)->fb, (*raiz)->dir->fb);
				//printf("======= %d ========\n",(*raiz)->chave);
				
				if ((*raiz)->fb == 0)
					return 0;
				
				return 1;
			}
			else
			{
				if ((*raiz)->esq != NULL)
					(*raiz)->fb -= 3;
				else
					(*raiz)->fb -= 2;
				
				(*raiz)->dir->fb++;
				rotacaoDir(&((*raiz)->dir));
				rotacaoEsq(raiz);
				
				if ((*raiz)->fb > 0)
					(*raiz)->fb--;
				
				//printf("Rotacao Dupla (2)\n");
				//printf("--- FBs ---\n%d\n", (*raiz)->esq->fb);
				//printf("%d\n%d\n------\n", (*raiz)->fb, (*raiz)->dir->fb);
				return 0;
			}
		} break;
		
		case -2:
		{		
			//printf("Posicao %d\n", (*raiz)->chave);
			//printf("FB Real: %d\n", (*raiz)->fb);
			
			if ((*raiz)->esq->fb <= 0)
			{
				(*raiz)->fb += 2;
				rotacaoDir(raiz);
				(*raiz)->fb++;
				
				//printf("Rotacao Simples Direita\n");
				//printf("--- FBs ---\n%d\n", (*raiz)->esq->fb);
				//printf("%d\n%d\n------\n", (*raiz)->fb, (*raiz)->dir->fb);
				
				if ((*raiz)->fb == 0)
					return 0;
				
				return 1;
			}
			else
			{
				
				if ((*raiz)->dir != NULL)
					(*raiz)->fb += 3;
				else
					(*raiz)->fb += 2;
				
				(*raiz)->esq->fb--;
				rotacaoEsq(&((*raiz)->esq));
				rotacaoDir(raiz);
				
				//printf("=== %d ===\n", (*raiz)->chave);
				if ((*raiz)->fb < 0)
					(*raiz)->fb++;
				
				//printf("Rotacao Dupla (-2)\n");
				//printf("--- FBs ---\n%d\n", (*raiz)->esq->fb);
				//printf("%d\n%d\n------\n", (*raiz)->fb, (*raiz)->dir->fb);
				return 0;
			}
		} break;
	}
	exit(0);
}

char insereAVL2(TNoAVL **raiz, int key)
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
		//printf("Inseriu\n");
		*raiz = novo;
		return 1;
	}
	
	//printf("--- Raiz: %d FB: %d---\n", (*raiz)->chave, (*raiz)->fb);
	//printf("Chave: %d\n", key);
	
	if (key < (*raiz)->chave)
	{
		//printf("- Esquerda\n");
		cresceu = insereAVL2(&((*raiz)->esq),key);
		//printf("Voltou-esq: %d raiz: %d FB: %d\n", cresceu, (*raiz)->chave, (*raiz)->fb-cresceu);
		
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
							//printf("Rotacao Simples Direita\n");
							if ((*raiz)->dir)
								(*raiz)->fb = 1;
							else
								(*raiz)->fb = 0;
							rotacaoDir(raiz);
							(*raiz)->fb = 0;
						}
						else
						{
							//printf("Rotacao Dupla (-2)\n");
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
		else
			return 0;
	}
	else
		if (key > (*raiz)->chave)
		{
			//printf("- Direita\n");
			cresceu = insereAVL2(&((*raiz)->dir),key);
			//printf("Voltou-dir: %d raiz: %d FB: %d\n", cresceu, (*raiz)->chave, (*raiz)->fb+cresceu);
			
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
								//printf("Rotacao Simples Esquerda\n");
								if ((*raiz)->esq)
									(*raiz)->fb = -1;
								else
									(*raiz)->fb = 0;
								rotacaoEsq(raiz);
								(*raiz)->fb = 0;
							}
							else
							{
								//printf("Rotacao Dupla (2)\n");
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
			else
				return 0;
		}
	printf("Ocorreu um erro!\n");
	exit(0);
}

TNoAVL **buscaPP(TNoAVL **raiz, int key) //usando ponteiro de ponteiro
{
	assert(raiz);	
	
	if ((*raiz) == NULL)
		return NULL;
	
	if ((*raiz)->chave == key)
		return raiz;
	
	if (key > (*raiz)->chave)
	{
		//printf("direita\n");
		return buscaPP(&((*raiz)->dir),key);
	}
	
	if (key < (*raiz)->chave)
	{
		//printf("esquerda\n");
		return buscaPP(&((*raiz)->esq),key);
	}
	
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
