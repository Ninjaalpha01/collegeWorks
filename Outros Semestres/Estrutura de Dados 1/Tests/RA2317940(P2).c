//Aluno: Gabriel Leonardo Martins de Oliveira
//RA: 2317940

#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int chave;
	struct no *prox;
}TNo;

TNo *criaLista();
TNo *alocaNo(int n);
TNo *copiaLista(TNo **list);
TNo *buscaNoCabeca(TNo *proximo, int key);
void insereInicio(TNo *lista, int chave); 
void imprime(TNo *paux);
void remove_todos(TNo **proximo);
void inssub(TNo **L1, int i1, TNo *L2, int i2, int len); //--> voce deve implementar
//void remove_todos(TNo **p) --> voc? deve implementar

int main()
{
	TNo *cabecaL1 = criaLista();
	TNo *cabecaL2 = criaLista();
	TNo *vet_p[4]; //-->exemplo vetor de ponteiros
	int op=0, i1, i2, len;
	
	int i=0, j=0, x=0;
	
	while(op!=5)
	{
		printf("\n1 - Insere lista 1 e 2");
		printf("\n2 - Sub lista 2 --> Lista 1");
		printf("\n3 - Imprime todas as listas");
		printf("\n4 - Remove todas as listas");
		printf("\n5 - Sair");
		printf("\nInforme opcao:");
		scanf("%d",&op);
		switch(op)
		{
			case 1: 
			{
				insereInicio(cabecaL1,9);
				insereInicio(cabecaL1,3);
				insereInicio(cabecaL1,5);
				insereInicio(cabecaL1,11);
				insereInicio(cabecaL1,90);
				insereInicio(cabecaL1,1);
				insereInicio(cabecaL1,12);
				insereInicio(cabecaL1,97);
				insereInicio(cabecaL1,22);
				insereInicio(cabecaL1,11);
				insereInicio(cabecaL1,6);
				insereInicio(cabecaL1,17);
				insereInicio(cabecaL2,32);
				insereInicio(cabecaL2,45);
				insereInicio(cabecaL2,92);
				insereInicio(cabecaL2,21);
				insereInicio(cabecaL2,71);
				insereInicio(cabecaL2,67);
				insereInicio(cabecaL2,19);
			}break;
			case 2:
				{
					
					if (j >= 4)
					{
						printf("\nLimite de insercoes excedido!\n");
						break;
					}
					int n1, n2;
					
					if (cabecaL1->prox == NULL || cabecaL2->prox == NULL)
					{
						printf("\nUma/As duas listas esta vazia!\n");
						break;
					}
					
					n1 = length(cabecaL1);
					n2 = length(cabecaL2);
					
					x = 1;
					while (j < 4 && x == 1)
					{
						//n?o esque?a de verificar lista vazia....
						printf("\nInforme posicao insercao Lista 1:");
						scanf("%d",&i1);
						
						vet_p[i] = buscaNoCabeca(cabecaL1,i1);
						if (vet_p[i] == NULL)
						{
							printf("i1 nao encontrado!\n");
							break;
						}
						i++;
						
						printf("\nInforme posicao insercao Lista 2:");
						scanf("%d",&i2);
						printf("\nInforme quantos elementos da lista 2 serao copiados na Lista 1:");
						scanf("%d",&len);
						
						if (len <= 0)
						{
							printf("\n--- len inválido! ---\n\n");
							break;
						}
						
						if (i1 > (n1+1))
							printf("\nLista 1 contem %d nos\n", n1);
						
						else
						{
							if ((i2+len-1) > n2)
								printf("\nLista 2 contem %d nos\n", n2);
							
							else
								if (i1 < 1 || i2 < 1)
								{
									printf("\n--- Erro! ---\n");
									break;
								}
						}
						
						inssub(&cabecaL1->prox,i1,cabecaL2,i2,len);
						j++;
						x--;
					}
					//rotina para inserir sub-lista a L2 na Lista l1
					//void inssub(TNo **L1, i1, TNo *L2, i2, len);
				}break;
			case 3:
				{
					printf("\nLista 1:\n");
					imprime(cabecaL1->prox);
					printf("\nLista 2:\n");
					imprime(cabecaL2->prox);
				}break;
			case 4:
				{
					if (cabecaL1->prox == NULL || cabecaL2->prox == NULL)
					{
						printf("\nUma/As duas listas esta vazia!\n");
						break;
					}
					remove_todos(&cabecaL1->prox);
					remove_todos(&cabecaL2->prox);
					//rotina para remover todos os elementos de
					// todas as listas existentes 
					//void remove_todos(TNo **p)	
				}
		}
	}
}

TNo *criaLista()
{
	TNo *cabeca = (TNo *)malloc(sizeof(TNo));
	if (cabeca == NULL)
		return NULL;
	
	cabeca->chave = 0; //valor reservado
	cabeca->prox = NULL;
	
	return cabeca;
}

TNo *alocaNo(int n)
{
	TNo *p=NULL;
	p = (TNo *)malloc(sizeof(TNo));
	if(p==NULL) printf("\nSO nao liberou memoria!");
	p->chave = n;
	p->prox = NULL;
    return p; 
}

void insereInicio(TNo *lista, int chave)
{ /* Supor que o valor de chave ? 7 */ 
	TNo *novo;
	novo = alocaNo(chave);
	if(novo == NULL)
		return;
	
	novo->prox = lista->prox;
	lista->prox = novo;
}

void imprime(TNo *paux)
{
	if(paux==NULL) printf("\nLista vazia!");
	else
	{
		while(paux!=NULL)
		{
			printf("\n%d", paux->chave);	
			paux=paux->prox;
		}
	}
}

void inssub(TNo **L1, int i1, TNo *L2, int i2, int len)
{
	if (L2 == NULL || *L1 == NULL)
	{
		printf("\nUma/As duas lista(s) esta vazia!\n");
		return;
	}
	
	TNo *copyl2 = NULL, *auxl1 = *L1, *auxl2, *proxi1 = NULL;
	int i;
	
	copyl2 = copiaLista(&L2->prox);
	
	auxl1 = buscaNoCabeca(*L1,i1); //busca o elemento i1 na L1
	
	auxl2 = buscaNoCabeca(copyl2,i2); //busca o elemento i2 na copia da L2
	if (auxl2 == NULL)
	{
		printf("i2 nao encontrado!\n");
		return;
	}
	
	proxi1 = auxl1->prox; // salva o proximo no depois de i1
	for (i=0; i < len; i++) //coloca todos os elementos selecionados da lista 2 na lista 1
	{
		auxl1->prox = auxl2;
		auxl1 = auxl1->prox;
		auxl2 = auxl2->prox;
	}
	auxl1->prox = proxi1; // recoloca o restante da lista (parte depois de i1)
}

TNo *copiaLista(TNo **list)
{
	TNo *nova = criaLista(), *aux = nova, *aux2 = *list;
	
	while(aux2 != NULL)
	{
		insereInicio(aux,aux2->chave);
		aux = aux->prox;
		aux2 = aux2->prox;
	}
	
	return nova;
}

TNo *buscaNoCabeca(TNo *prim, int key)
{
	TNo *aux = prim;
	
	while (aux != NULL)
	{
		if(aux->chave == key)
			return aux;

		aux = aux->prox;
	}
	return NULL;
}

int length(TNo *list)
{
	int n=0;
	TNo *aux = list;
	
	while (aux != NULL)
	{
		aux = aux->prox;
		n++;
	}
	return n;
}

void remove_todos(TNo **proximo)
{
	if (*proximo == NULL)
		return;
	
	remove_todos(&(*proximo)->prox);
	
	(*proximo)->prox = NULL;
	free(*proximo);
	*proximo = NULL;
}
