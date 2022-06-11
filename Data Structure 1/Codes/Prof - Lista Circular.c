#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct lista{
	int chave;
	struct lista *prox;
}TipoListaCircular;

void insereCircular(TipoListaCircular **p, int info)
{
    assert(p);	
    if(*p == NULL)
    {	
        *p = (TipoListaCircular *) malloc(sizeof(TipoListaCircular));
         if(*p != NULL)
          {	
			(*p)->chave = info;
			(*p)->prox = *p;
          }	
   }
   else
    {
        TipoListaCircular *aux = (TipoListaCircular *) malloc(sizeof(TipoListaCircular));
        if (aux == NULL) return;
        aux->chave = info;		
        aux->prox = (*p)->prox;	
        (*p)->prox = aux;	
       // (*p)=(*p)->prox; //*p=aux; mais antigo ou mais recente
    }
}

void removeCircular(TipoListaCircular **p)
{
    assert(p);	
    if(*p == NULL) 
	{
		printf("Lista vazia!");	
		return;
	} 
	
    TipoListaCircular *pPrim = (*p)->prox;
    TipoListaCircular *pPenult = (*p)->prox;
    
    if(pPrim->prox != pPrim)
    {
       while(pPenult->prox != *p)
       {
			pPenult = pPenult->prox;
       }
      free(*p);
      *p = pPenult;
       pPenult->prox = pPrim;
    } //if
    else
     {
	   free(*p);
	   *p = NULL;
	   printf("Agora a lista esta vazia!\n");
     }
}	

void removeMeioCircular(TipoListaCircular **prim, int key)
{
	assert(prim);
	if (*prim == NULL)
	{
		printf("Lista vazia!\n");
		return;
	}
	
	TipoListaCircular *aux = *prim, *ant = *prim;
	
	if ((*prim)->chave == key)
	{
		while (ant->prox != *prim)
			ant = ant->prox;
		
		*prim = (*prim)->prox;
		ant->prox = *prim;
		free(aux);
		return;
	}
	
	aux = aux->prox;
		
	while (aux != *prim)
	{
		if (aux->chave == key)
		{
			ant->prox = aux->prox;
			free(aux);
			return;
		}
		ant = aux;
		aux = aux->prox;
	}
	
	printf("Valor nao encontrado!\n");
}

TipoListaCircular *buscaNoCircular(TipoListaCircular *prim, int key)
{
	TipoListaCircular *aux = prim;
	
	do
	{
		if (aux->chave == key)
			return aux;
		
		aux = aux->prox;
	} while (aux != prim);
	
	return NULL;
}

void imprime(TipoListaCircular *p)
{
	
	if (p==NULL)
	{
		printf("\nLista Vazia!");
		return;
	}
	TipoListaCircular *aux=p->prox;
	do
	{
		printf("%d\n", aux->chave);
		aux = aux->prox;
	} while (p!=aux);
	printf("%d\n", p->chave);
}

void insereMeio(TipoListaCircular **prim, int key, int apos)
{
	TipoListaCircular *aux=NULL, *novo=NULL;
	
	aux = *prim;
	novo = (TipoListaCircular *) malloc(sizeof(TipoListaCircular));
	novo->chave = key;
	
	do
	{
		if (aux->chave == apos)
		{
			novo->prox = aux->prox;
			aux->prox = novo;
			return;
		}
		aux = aux->prox;
	} while(aux != *prim);
	
	printf("Chave nao encontrada!\n");
}

int main()
{
	TipoListaCircular *lista=NULL;
	insereCircular(&lista, 89);
	insereCircular(&lista, 25);
	insereCircular(&lista, 44);
	insereCircular(&lista, 23);
	insereCircular(&lista, 19);
	imprime(lista);
//	insereMeio(&lista,36,23);
//	insereMeio(&lista,27,19);
	
	
	printf("\nAlterado!\n");
	removeMeioCircular(&lista,55);
//	removeCircular(&lista);
	imprime(lista);
	
	TipoListaCircular *achei;
	
	achei = buscaNoCircular(lista,23);
	printf("\n---%d---\n", achei->chave);
	
//	printf("\n%d", lista->chave);

	return 0;
}
