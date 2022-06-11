#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int TipoChave;
typedef int TipoValor;

typedef struct TipoListaSimples
{
	TipoChave chave;
	TipoValor valorQualquer;
	struct TipoListaSimples *prox;
} TipoLista;

TipoLista *alocaNo(TipoChave key);
TipoLista *criaLista();
TipoLista *insereInicioCabeca(TipoLista *cabeca, TipoChave chave);
void atualizaValor(TipoLista *cabeca, TipoValor novoValor);
void removePrimeiroNo(TipoLista **cabeca);
TipoLista *pesquisaNo(TipoLista *cabeca, TipoChave chave);
TipoLista *insereFimCabeca(TipoLista *cabeca, TipoChave chave);

int main()
{
	TipoLista *cabeca=NULL, *aux=NULL, *achei=NULL;
	int key;
	
	cabeca = criaLista();
	
	if (cabeca != NULL)
		printf("Lista criada!\n");
	
	else
		printf("Erro ao criar a lista!\n");
	
	cabeca = insereInicioCabeca(cabeca,23);
	cabeca = insereInicioCabeca(cabeca,7);
	cabeca = insereInicioCabeca(cabeca,15);
	cabeca = insereInicioCabeca(cabeca,95);
	
//	atualizaValor(cabeca,285);
	removePrimeiroNo(&cabeca);
//	
//	printf("chave: ");
//	scanf("%d", &key);
//	achei = pesquisaNo(cabeca,key);
//	
//	if (achei != NULL)
//	{
//		printf("\n=== ACHEI ===\n");
//		printf("chave: %d\n", achei->chave);
//		printf("valor: %d\n", achei->valorQualquer);
//	}
//	
//	else
//		printf("== NAO ACHEI ==\n");
	
	insereFimCabeca(cabeca,900);
	
	while (cabeca->prox!=NULL && cabeca!=NULL)
	{
		printf("\nchave: %d\n", cabeca->chave);
		printf("valor: %d\n\n", cabeca->valorQualquer);
		cabeca = cabeca->prox;
	}
	
	return 0;
}

TipoLista *alocaNo(TipoChave key)
{
	TipoLista *no=NULL;
	
	no = (TipoLista *)malloc(sizeof(TipoLista));
	
	if (no == NULL)
	{
		printf("SO nao liberou memoria!\n");
		return NULL;
	}
	
	no->chave = key;
	no->valorQualquer = key;
	no->prox = NULL;
	return no;
}

TipoLista *criaLista()
{
	TipoLista *noc=NULL;
	
	noc = (TipoLista *)malloc(sizeof(TipoLista));
	
	if (noc == NULL)
		return NULL;
	
	noc->chave = -1;
	noc->valorQualquer = -1;
	noc->prox = NULL;
	
	return noc;
}

TipoLista *insereInicioCabeca(TipoLista *cabeca, TipoChave chave)
{
	TipoLista *novo=NULL;
	novo = alocaNo(chave);
	
	if (novo == NULL)
		return NULL;
	
	novo->prox = cabeca;
	return novo;
}

void atualizaValor(TipoLista *cabeca, TipoValor novoValor)
{
	if (cabeca != NULL)
	{
		cabeca->valorQualquer = novoValor;
		printf("Valor atualizado!\n");
	}
	
	else
		printf("Lista vazia!\n");
}

void removePrimeiroNo(TipoLista **cabeca)
{
	assert(cabeca);
	if (cabeca == NULL)
		return;
	
	TipoLista *aux = *cabeca;
	
	*cabeca = (*cabeca)->prox;
	free(aux);
	aux = NULL;
}

TipoLista *pesquisaNo(TipoLista *cabeca, TipoChave chave)
{
	assert(cabeca);
	if (cabeca == NULL)
		return;
	
	TipoLista *aux=cabeca;
	
	do
	{
		if (chave == aux->chave)
			return aux;
			
		aux = aux->prox;
	} while (aux->prox != NULL);
	
	return NULL;
}

TipoLista *insereFimCabeca(TipoLista *cabeca, TipoChave chave)
{
	TipoLista *aux=cabeca, *novo=NULL;
	
	novo = alocaNo(chave);
	
	if (novo == NULL)
	{
		printf("Operacao incompleta!\n");
		return NULL;
	}
	
	while (aux->prox->prox != NULL)
		aux = aux->prox;
	
	novo->prox = aux->prox;
	aux->prox = novo;
}
