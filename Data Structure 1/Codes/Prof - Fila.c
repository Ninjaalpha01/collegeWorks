#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int chave;
	//campos....
	struct no *prox;
}TNo;

TNo *alocaNo(int k)
{
	TNo *novo;
	novo = (TNo *)malloc(sizeof(TNo));
	if (novo == NULL) return NULL;
	novo->chave = k;
	novo->prox = NULL;
	return novo; 
}

TNo *insereFim(int k,TNo *paux)
{
	TNo *novo;
	novo = alocaNo(k);
	if(novo==NULL) return NULL;
	if(paux != NULL)
		paux->prox = novo;
	return novo;
	
}

void imprimeLista(TNo *paux)
{
	while(paux!=NULL)
	{
		printf("\n%d", paux->chave);
		paux = paux->prox;
	}
}

TNo *removeLista(TNo *paux)
{
	TNo *aux= paux;
	
	if(paux->prox!=NULL)
	{
		paux = paux->prox;
		free(aux);
		return paux;
	}
	else
	{
		free(aux);
		return NULL;
	}   
}

int main()
{
	TNo *inicio=NULL, *final=NULL;
	int op=1,chave;
	while(op!=4)
	{
		printf("\n1 - Insere");
		printf("\n2 - Retira");
		printf("\n3 - Imprime");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				{
					printf("\nInforme valor:");
					scanf("%d",&chave);
					final = insereFim(chave,final);
					if(inicio == NULL) 
						inicio = final;
				} break;
			case 2:
				{
					if(inicio==NULL)
						printf("\nLista vazia!");
					else
					{
						inicio=removeLista(inicio);
				   		if(inicio == NULL) 
							final = NULL;
					}
				} break;
			case 3:
				{
					if(inicio==NULL)
						printf("\nLista vazia!");
					imprimeLista(inicio);	
				} break;			
		}
	}
}
