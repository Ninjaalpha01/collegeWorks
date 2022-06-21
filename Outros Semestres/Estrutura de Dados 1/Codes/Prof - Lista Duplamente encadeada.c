#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct listaEnc
{ 
    int info; 
    struct listaEnc* ant; 
    struct listaEnc* prox; 
}ListaE; 

ListaE* listaE_insere (ListaE* p, int info) 
{ 
  //  assert(p);
    ListaE* novo = (ListaE*) malloc(sizeof(ListaE)); 
    novo->info = info; 
    novo->prox = p; 
    novo->ant = NULL; 
    /* verifica se lista n?o estava vazia */ 
    if (p != NULL) 
         p->ant = novo; 
   return novo; 
} 

void listaE_imprime(ListaE *prim) 
{
	if (prim == NULL)
	{
		printf("\nLista vazia!");
		return;
	}
	
	else
	{
		if (prim->ant == NULL)
			while (prim != NULL)
			{
				printf("%d\n", prim->info);
				prim = prim->prox;
			}
		
		else
			while (prim != NULL)
			{
				printf("%d\n", prim->info);
				prim = prim->ant;
			}
	}
}

void listaE_imprime2 (ListaE *p) 
{ 
    ListaE *paux; 
    if(p==NULL) printf("\nLista vazia!");
    for (paux=p; paux!=NULL; paux=paux->ant) 
         printf("\n%d", paux->info);
    //return NULL; /* n?o achou o elemento */
 }

ListaE *listaE_busca (ListaE *p, int elem) 
{ 
    ListaE *paux = p; 
    while (paux != NULL) 
    {
	    if (paux->info == elem) 
            return paux; 
    	paux = paux->prox;
    }
    return NULL; /* n?o achou o elemento */
 }

void listaE_remove (ListaE **p, int elem) 
{ 
    ListaE *apagar, *anterior, *proximo;
     
    for (apagar=*p; apagar!=NULL; apagar=apagar->prox) 
         if (apagar->info == elem) 
            break;
    
    if(apagar==NULL)
		printf("\nElemento nao encontrado!");
	
    else
    {
    	if(apagar==*p)
    	{
    		*p = apagar->prox;
    		(*p)->ant = NULL;
    		free(apagar);
		}
		else
		{
		  if (apagar->prox == NULL)
		  {
		  	anterior = apagar->ant;
		  	anterior->prox = NULL;
		  	free(apagar);
		  	apagar = NULL;
		  	return;
		  }
		  anterior= apagar->ant;
    	  proximo= apagar->prox;
    	  anterior->prox = proximo;
    	  proximo->ant = anterior;
    	  free(apagar);
    	  apagar=NULL;
		}
		
	}
}

void insereMeioEnca(ListaE **prim, int key, int apos)
{
	ListaE *ant=NULL, *aux=NULL, *novo=NULL;
	
	aux = *prim;
	ant = *prim;
	novo = (ListaE *) malloc(sizeof(ListaE));
	novo->info = key;
	
	do
	{
		if (aux->info == apos && aux == *prim)
		{
			novo->prox = aux->prox;
			novo->ant = NULL;
			aux->prox = novo;
			return;
		}
		else
			if (aux->info == apos)
			{
				novo->prox = aux->prox;
				novo->ant = ant;
				aux->prox = novo;
				return;
			}
			aux = aux->prox;
			ant = aux->ant;
	} while (aux != NULL);
	
	printf("\nChave nao encontrada!\n");
}

void listaE_removePrim(ListaE **ponta)
{
	assert(ponta);
	if (*ponta == NULL)
	{
		printf("Lista Vazia!\n");
		return;
	}
	
	ListaE *aux = *ponta;
	
	if ((*ponta)->ant != NULL || (*ponta)->prox != NULL)
	{
		if ((*ponta)->ant == NULL)
		{
			*ponta = (*ponta)->prox;
			(*ponta)->ant = NULL;
		}
		else
		{
			*ponta = (*ponta)->ant;
			(*ponta)->prox = NULL;
		}
	}
	else
		*ponta = NULL;
	
	free(aux);
	
	if (*ponta == NULL)
		printf("Agora a lista esta vazia!\n");
}

int main()
{
	ListaE *prim=NULL, *ult=NULL;
	prim = listaE_insere(prim, 9);
	ult=prim;
	prim = listaE_insere(prim, 3);
	prim = listaE_insere(prim, 2);
	prim = listaE_insere(prim, 7);
//	printf("\n%d", prim->info);
	listaE_imprime(prim);
	printf("Invertido\n");
	listaE_imprime(ult);
//	insereMeioEnca(&prim,25,9);
	printf("\nAlterado!\n");
	listaE_remove(&prim,2);
	listaE_imprime(prim);
//	listaE_imprime2(ult);
//	listaE_remove(&prim,7);
//	listaE_imprime(prim);
//	prim = listaE_insere(prim, 13);
//	listaE_imprime(prim);
	
	ListaE *achei = listaE_busca(prim,7);
	if (achei != NULL)
		printf("\n---%d---\n", achei->info);
	else
		printf("nao encontrado!");
	
	
	return 0;
}

