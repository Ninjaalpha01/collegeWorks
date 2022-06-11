#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;
typedef int TipoValor;

struct TipoListaSimples
{
	TipoChave chave;
	TipoValor valorQualquer;
	struct TipoListaSimples *prox;
};

typedef struct TipoListaSimples TipoListaSimples;

TipoListaSimples *alocano(int key, int valor)
{
	TipoListaSimples *no=NULL;
	no = (TipoListaSimples *)malloc(sizeof(TipoListaSimples));
	if (no == NULL)
		return NULL;
	
	no->chave = key;
	no->valorQualquer = valor;
	no->prox = NULL;
	return no;
}

TipoListaSimples *insereInicioListaSimples(TipoListaSimples **prim, TipoChave chave, TipoValor valor)
{
	TipoListaSimples *noaux=NULL;
	
	noaux = alocano(chave,valor);
	
	if (noaux == NULL)
		exit(0);
	
	noaux->prox = *prim;
	
	return noaux;
}

void atualizaValor(TipoListaSimples *prim, TipoValor novoValor)
{
	if (prim != NULL)
		prim->valorQualquer = novoValor;
	else
		printf("Nao ha valor a se alterar!\n");
}

void removePrimeiroNo(TipoListaSimples **prim)
{	
	if (*prim != NULL)
	{
		TipoListaSimples *noaux=NULL;
		noaux = (TipoListaSimples *)malloc(sizeof(TipoListaSimples));
		
		noaux = *prim;
		*prim = noaux->prox;
		
		free(noaux);
	}
}

TipoListaSimples *pesquisaNo(TipoListaSimples *prim, TipoChave chave)
{
	int i;
	TipoListaSimples *achei=NULL;
	
	while(prim != NULL)
	{
		if (chave == prim->chave)
		{
			achei = prim;
			achei->valorQualquer = prim->valorQualquer;
			achei->prox = prim->prox;
		
			return achei;
		}
		prim = prim->prox;
	}
	
	return NULL;
}

TipoListaSimples *insereFimListaSimples(TipoListaSimples **prim, TipoChave chave)
{
	TipoListaSimples *ulti=NULL, *noaux=NULL;
	
	noaux = (TipoListaSimples *)malloc(sizeof(TipoListaSimples));
	ulti = *prim;
	
	noaux->chave = chave;
	noaux->valorQualquer = 2077;
	noaux->prox = NULL;
	
	while(ulti->prox!=NULL)
		ulti = ulti->prox;
	
	ulti->prox = noaux;
	
	return noaux;
}

void removeUltimoNo(TipoListaSimples **prim)
{
	TipoListaSimples *ulti=NULL;
	
	ulti = *prim;
	
	while(ulti->prox->prox!=NULL)
		ulti = ulti->prox;
	
	ulti->prox = NULL;
}

void removeNo(TipoListaSimples **prim, TipoChave chave)
{
	int i, j=0, k=0;
	TipoListaSimples *achei=NULL, *noaux=NULL;
	
	achei = *prim;
	noaux = *prim;
	
	for(i=0; noaux!=NULL && i<2; i++)
	{
		j++;
		if (chave == noaux->chave)
		{
			k = 1;
			if (j==1)
			{
				*prim = achei->prox;
				break;
			}
			achei->prox = noaux->prox;
			break;
		}
		noaux = noaux->prox;
		
		if (i==1)
		{
			achei = achei->prox;
			i=0;
		}
	}
	if (!k)
	{
		printf("\n---No nao encontrado!---\a\n\n");
		system("pause");
	}
}

void liberaNos(TipoListaSimples **prim)
{
	TipoListaSimples *ulti=NULL, *noaux=NULL;
	
	if (*prim != NULL)
	{
		noaux = *prim;
		ulti = *prim;
		while (noaux!=NULL)
		{
			noaux = ulti->prox;
			free(ulti);
			ulti = noaux;
		}
		free(noaux);
		*prim = NULL;
	}
}

TipoListaSimples *copiaListas(TipoListaSimples *prim)
{
	TipoListaSimples *copy=NULL;
	
	copy = (TipoListaSimples *)malloc(sizeof(TipoListaSimples));
	
	if (copy==NULL) return NULL;
	
	do
	{
		copy->chave = prim->chave;;
		copy->valorQualquer = prim->valorQualquer;
		copy->prox = prim->prox;
	} while (prim->prox == NULL);
	
	return copy;
}
