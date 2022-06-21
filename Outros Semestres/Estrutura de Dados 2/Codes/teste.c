#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct TNoABP
{
	int chave;
	struct TNoABP *esq;
	struct TNoABP *dir;
} typedef TNoABP;

TNoABP *buscaABP(TNoABP *r, int key) //usando ponteiro
{
	//caso base
	if (r == NULL) //arvore vazia
		return NULL;
	
	if (key == r->chave)
		return r;
	
	if (key < r->chave)
		return buscaABP(r->esq,key);
	else
		return buscaABP(r->dir,key);
	
	/*busca nao recursiva
	while (r != NULL)
	{
		if (key == r->chave)
			return r;
		if (key < r->chave)
			r = r->esq;
		else
			r = r->dir;
	}
	return NULL;
	*/
}

TNoABP **buscaPP(TNoABP **raiz, int key);
TNoABP *insereABP(TNoABP **r, int key);
TNoABP **ppMenor(TNoABP **sub);
//TNoABP **reinsercao(TNoABP **raiz, TNoABP **sub);
void removeNoABP(TNoABP **raiz, int key);
void substituiDados(TNoABP **orig, TNoABP **sub);
void printABP(TNoABP *raiz);
void preOrdem(TNoABP *raiz);
void ordem(TNoABP *raiz);
void posOrdem(TNoABP *raiz);
void rotacaoEsq(TNoABP **raiz);
void rotacaoDir(TNoABP **raiz);

int main()
{
	TNoABP *raiz = NULL; //arvore nasce vazia!
	
	//inserindo o dado 85 na ABP raiz
	insereABP(&raiz,52);
	insereABP(&raiz,22);
	insereABP(&raiz,85);
	insereABP(&raiz,8);
	insereABP(&raiz,43);
	//insereABP(&raiz,81);
	insereABP(&raiz,96);
	insereABP(&raiz,1);
	insereABP(&raiz,11);
	insereABP(&raiz,26);
	//insereABP(&raiz,69);
	//insereABP(&raiz,65);
	insereABP(&raiz,100);
	
	TNoABP **pp = NULL;
	int x, i=1;
	
	while (i != 1) // trocar valor para repetir o loop
	{
		printABP(raiz);
		
		printf("Insira para busca: ");
		scanf("%d", &x);
		
		pp = buscaPP(&raiz,x);
		
		if (pp == NULL)
			printf("Nao achei\n");
		else
			printf("Achei: %d\n", (*pp)->chave);
		
		printf("Insira para remover: ");
		scanf("%d", &x);
		
		removeNoABP(&raiz,x);
		i++;
	}
	
	// travessias
	printABP(raiz);
	
	printf("\nIMPRIMINDO EM PRE-ORDEM:\n");
	
	preOrdem(raiz);
	
	printf("\nIMPRIMINDO EM ORDEM:\n");
	
//	ordem(raiz);
	
	printf("\nIMPRIMINDO EM POS-ORDEM:\n");
	
//	posOrdem(raiz);
	
	posOrdem(raiz);

/*
	// rotacoes (Se deixar as duas habilitadas a ABP permanecera a mesma)
	printf("Rotacao Esquerda:\n");
	rotacaoEsq(&raiz);
	preOrdem(raiz);
*/
	//rotacao especifica no no desejado
	/*
	pp = buscaPP(&raiz,85); //e necessario uma busca pelo fb
	rotacaoEsq(pp);
	preOrdem(raiz);
	printf("ordem:\n");
	ordem(raiz);
	*/
/*	
	printf("Rotacao Direita:\n");
	rotacaoDir(&raiz);
	preOrdem(raiz);
*/
		
	return 0;
}

void printABP(TNoABP *raiz)
{
	if (raiz==NULL)
		return;
	
	printABP(raiz->esq);
	printf("%d\n", raiz->chave);
	printABP(raiz->dir);
}

TNoABP **buscaPP(TNoABP **raiz, int key) //usando ponteiro de ponteiro
{
	assert(raiz);	
	
	if ((*raiz) == NULL)
		return NULL;
	
	if ((*raiz)->chave == key)
		return raiz;
	
	if (key > (*raiz)->chave)
	{
		printf("direita\n");
		return buscaPP(&((*raiz)->dir),key);
	}
	
	if (key < (*raiz)->chave)
	{
		printf("esquerda\n");
		return buscaPP(&((*raiz)->esq),key);
	}
	
	return NULL;
	
	/* interativo
	while (*raiz != NULL)
	{
		if ((*raiz)->chave == key)
			return raiz;
		
		if ((*raiz)->chave > key)
			raiz = &((*raiz)->dir);
		
		if ((*raiz)->chave < key)
			raiz = &((*raiz)->esq);
	}
	*/
}

TNoABP *insereABP(TNoABP **r, int key)
{
	TNoABP *novo = NULL;
	
	novo = (TNoABP *)malloc(sizeof(TNoABP));
	
	if (novo == NULL)
	{
		printf("SO nao liberou memoria!\n");
		return NULL;
	}
	
	novo->chave = key;
	novo->esq = NULL;
	novo->dir = NULL;
	
	if ((*r) == NULL)
	{
		*r = novo;
		return novo;
	}
	
	if (key < (*r)->chave)
	{
		if ((*r)->esq == NULL)
		{
			(*r)->esq = novo;
			return novo;
		}
		insereABP(&((*r)->esq),key);
	}
	else
		if (key > (*r)->chave)
		{
			if ((*r)->dir == NULL)
			{
				(*r)->dir = novo;
				return novo;
			}
			insereABP(&((*r)->dir),key);
		}
		
	return NULL;
}

void removeNoABP(TNoABP **raiz, int key)
{
	TNoABP **pp = buscaPP(raiz,key);
	if (pp == NULL)
	{
		printf("Elemento nao encontrado!\n");
		return;
	}
	
	if ((*pp)->esq == NULL && (*pp)->dir == NULL) //caso 1 - no folha
	{
		printf("caso 1:\n");
		free(*pp);
		*pp = NULL;
		return;
	}
	else
		if (((*pp)->esq == NULL) != ((*pp)->dir == NULL)) //caso 2 - um filho
		{
			printf("caso 2:\n");
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
			printf("caso 3:\n");
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

void preOrdem(TNoABP *raiz)
{
	if (!raiz)
		return;
	
	printf("%d\n", raiz->chave);
	preOrdem(raiz->esq);
	preOrdem(raiz->dir);
	
	return;
}

void ordem(TNoABP *raiz)
{
	if (!raiz)
		return;
	
	ordem(raiz->esq);
	printf("%d\n", raiz->chave);
	ordem(raiz->dir);
	
	return;
}

void posOrdem(TNoABP *raiz)
{
	if (!raiz)
		return;
	
	posOrdem(raiz->esq);
	posOrdem(raiz->dir);
	printf("%d\n", raiz->chave);
	
	return;
}

void rotacaoEsq(TNoABP **raiz)
{
	TNoABP *buffer=*raiz;
	
	(*raiz) = (*raiz)->dir;
	(*raiz)->esq = buffer;
	buffer->dir = NULL;
	
	return;
}

void rotacaoDir(TNoABP **raiz)
{
	TNoABP *buffer=*raiz;
	
	(*raiz) = (*raiz)->esq;
	(*raiz)->dir = buffer;
	buffer->esq = NULL;
	
	return;
}

/*
Mais para frente sera possivel
TNoABP **reinsercao(TNoABP **raiz, TNoABP **sub)
{
	TNoABP **nova=NULL;
	nova = buscaPP(raiz,(*sub)->chave);
}
*/
