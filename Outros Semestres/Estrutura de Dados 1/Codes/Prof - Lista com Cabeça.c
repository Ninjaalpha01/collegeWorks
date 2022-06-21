#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct No
{
  int chave;
  /* outros campos */
  struct No *prox;
}No;

//typedef struct NoC
//{
//  int chave;
  /* outros campos */
//  int n_nos;
//  struct No *prox;
//}NoC;


No *criaLista();
void insereInicio2(No *lista, int chave);
No *alocaNo(int k);
void imprimeLista(No *prim);
No *buscaNo(No *prim, int chave);
void removePrimeiro(No **prim);
void insereMeio(No **prim, int key, int apos);
void removeMeio(No **prim, int k);

int main()
{
	No *prim = criaLista();
	No *achou;
//	printf("\n%d", prim->chave);
	insereInicio2(prim,7);
//	printf("\n%d", prim->n_nos);
	insereInicio2(prim,12);
//	printf("\n%d", prim->n_nos);
	insereInicio2(prim,60);
//	printf("\n%d", prim->n_nos);
	imprimeLista(prim->prox);
	
	achou = buscaNo(prim->prox,55);
	
//	insereMeio(&prim,25,60);
//	imprimeLista(prim->prox);;
	
	
	
//	removePrimeiro(&prim->prox);
	removeMeio(&prim->prox,12);
	imprimeLista(prim->prox);
}

No *criaLista()
{
  No* cabeca = (No *)malloc(sizeof(No));
  if (cabeca == NULL) return NULL;
  cabeca->chave = -1; //valor reservado
//  cabeca->n_nos = 0;
  cabeca->prox = NULL;
  return cabeca;
}

void insereInicio2(No *lista, int k)
{ 
 assert(lista);
 No *novo;
 novo = alocaNo(k);
 if(novo == NULL) return ;
 novo->prox = lista->prox;
 lista->prox = novo;
 //lista->n_nos++;
}

No *alocaNo(int k)
{
 No *no; /* Supor em 0xc0 */
 no = (No *) malloc(sizeof(No)); 
                 /* Supor em 0xa0 */
 if (no == NULL) return NULL;
 no->chave = k;
 no->prox = NULL;
 return no;
}

void imprimeLista(No *prim)
{
	if (prim == NULL)
		printf("Lista vazia!\n");
	
	while(prim!=NULL)
	{
		printf("\n%d", prim->chave);
		prim = prim->prox;
	}
}

No *buscaNo(No *prim, int chave)
{
	No *aux=prim;
	while(aux!=NULL)
	{
		if(aux->chave == chave)
		  return aux;
		else aux = aux->prox;
	}
	return NULL;
}

void removePrimeiro(No **prim)
{
  assert(prim);
  if (*prim == NULL)
  {
  	printf("Lista vazia!\n");
  	return;
  }
  No *aux = *prim;
  *prim = (*prim)->prox;
  free(aux);
}

void insereMeio(No **prim, int key, int apos)
{
	if (*prim == NULL)
	{
		printf("Lista vazia!\n");
		return;
	}
	
	No *aux=NULL, *novo=NULL;
	
	aux = *prim;
	novo = alocaNo(key);
	
	while(aux->prox != NULL)
	{
		if (aux->chave == apos)
		{
			novo->prox = aux->prox;
			aux->prox = novo;
			return;
		}
		else
			aux = aux->prox;
	}
	
	printf("\nElemento nao encontrado!\n");
}

void removeMeio(No **prim, int k)
{
	No *aux = *prim, *ant = *prim;
	
	if ((*prim)->chave == k)
	{
		*prim = (*prim)->prox;
		free(aux);
		return;
	}
	
	aux = (*prim)->prox;
	
	while (aux!=NULL)
	{
		if(aux->chave == k)
			break;
		else
		{
			ant = aux;
			aux = aux->prox;
			
			if (aux == NULL)
			{
				printf("Valor nao encontrado!\n");
				return;
			}
		}
	}
	
	ant->prox = aux->prox;
	free(aux);
}


