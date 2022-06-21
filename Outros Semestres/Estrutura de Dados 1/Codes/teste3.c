#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;
typedef int TipoValor;
typedef struct No
{
  int chave;
  /* outros campos */
  int ValorQualquer;
  struct No *prox;
}No;




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

void imprimeLista(No *prim)
{
	while(prim!=NULL)
	{
		printf("\n%d", prim->chave);
		prim = prim->prox;
	}
}


void insereInicio(No **prim, int k)
{ 
  No* noAux = alocaNo(k);
  if (noAux == NULL) exit(0);//return NULL;
  noAux->prox = *prim;
  *prim = noAux;
}

void insereFinal(No *prim, int k)
{ 
  No* pa=prim; 
  No* noAux = alocaNo(k);
  if (noAux == NULL) exit(0);//return NULL;
  while(pa->prox!=NULL)
    {
    	pa = pa->prox;
	}
 
  pa->prox = noAux;

}

void inseremeio(No **prim, int k)
{
	No *aux=NULL, *novo=NULL;
	
	novo = alocaNo(k);
	aux = *prim;
	
	while(aux!=NULL)
	{
		if(aux->chave == 12)
		{
			novo->prox = aux->prox;
			aux->prox = novo;
			break;
		}
		else 
			aux = aux->prox;
	}
}

int main()
{
	
  No *prim = NULL, *pa = NULL, *prim2 = NULL;
	
  insereInicio(&prim, 7);//insira chave 7
  insereInicio(&prim, 12);//insira chave 12
  insereInicio(&prim, 16);//insira chave 7
  insereInicio(&prim, 18);//insira chave 12
  insereInicio(&prim, 70);//insira chave 7
  insereInicio(&prim, 120);//insira chave 12
  imprimeLista(prim);
	
	inseremeio(&prim,25);
	printf("alterado\n");
	imprimeLista(prim);	
	
	return 0;
}

