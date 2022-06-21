#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct No
{
  int chave;
  /* outros campos */
  int ValorQualquer;
  struct No *prox;
}No;
 //typedef struct No No;

No *alocaNo(int k);
void insereInicio(No **prim, int k);
void imprimeLista(No *prim);
void removePrimeiro(No **prim);
void insereFinal(No *prim, int k);
No *buscaNo(No *prim, int chave);
void removeMeio(No **prim, int k);

int main ()
{
  No *prim = NULL, *pa = NULL, *prim2 = NULL;
  //prim = alocaNo(7);
  insereInicio(&prim, 7);//insira chave 7
  insereInicio(&prim, 12);//insira chave 12
  insereInicio(&prim, 16);//insira chave 7
  insereInicio(&prim, 18);//insira chave 12
  insereInicio(&prim, 70);//insira chave 7
  insereInicio(&prim, 120);//insira chave 12
  imprimeLista(prim);
//  insereInicio(&prim2, 3);//insira chave 7
//  insereInicio(&prim2, 312);//insira chave 12
//  insereInicio(&prim2, 516);//insira chave 7
//  insereInicio(&prim2, 188);//insira chave 12
//  insereInicio(&prim2, 700);//insira chave 7
//  insereInicio(&prim2, 20);//insira chave 12
//  printf("\n============= Lista 2 ==========");
//  imprimeLista(prim2);
  printf("\n============= Remocao ==========");
//  removePrimeiro(&prim);
//  removePrimeiro(&prim);
  removeMeio(&prim,120);
  imprimeLista(prim);
//  printf("\n============= Insere Final =============");
//  insereFinal(prim,890);
//  imprimeLista(prim);
//  insereFinal(prim2,990);
//  printf("\n============= Insere Final =============");
//  imprimeLista(prim2);
//  pa = buscaNo(prim,7);
//  if(pa == NULL) 
//    printf("\n Valor nao encontrado!");
//  else printf("\n Valor %d", pa->chave);
//  
//  pa = buscaNo(prim,188);
//  if(pa == NULL) 
//     printf("\n Valor nao encontrado!");
//  else printf("\n Valor %d", pa->chave);
  
  return 0;
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

void insereInicio(No **prim, int k)
{ 
  assert(prim);  
  No* noAux = alocaNo(k);
  if (noAux == NULL) exit(0);//return NULL;
  noAux->prox = *prim;
  *prim = noAux;
}

void insereFinal(No *prim, int k)
{ 
  assert(prim); 
  No* pa=prim; 
  No* noAux = alocaNo(k);
  if (noAux == NULL) exit(0);//return NULL;
  while(pa->prox!=NULL)
    {
    	pa = pa->prox;
	}
 
  pa->prox = noAux;

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
  if (*prim == NULL)
  	printf("Agora a lista esta vazia!\n");
	
  free(aux);
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


