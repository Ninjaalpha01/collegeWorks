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

TipoListaSimples *alocano(int key, int valor);

/*
*1 -  Insercao no início
* Insere novo nó no início de uma lista encadeada.
* A referência de ponteiro para o primeiro nó e os 
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido 
* ou NULL em caso de insucesso.
*/
TipoListaSimples *insereInicioListaSimples(TipoListaSimples **prim, TipoChave chave, TipoValor valor);

/* 
* 2 - Atualiza primeiro no
* Caso o primeiro nó exista, atualiza o campo 
* valorQualquer com novoValor. É dado o ponteiro para
* o primeiro nó.
*/
void atualizaValor(TipoListaSimples *prim, TipoValor novoValor);

/* 
* 3 - Remoção no início
* Remove o primeiro nó de uma lista 
* caso ele exista. O segundo, se existir, passará 
* a ser o primeiro.
*/
void removePrimeiroNo(TipoListaSimples **prim);

/*
* 4 - Busca pelo endereço de um nó dado um valor de chave
* Devolve ponteiro para o nó cujo valor chave é 'chave'
* ou NULL caso este não exista.
*/
TipoListaSimples *pesquisaNo(TipoListaSimples *prim, TipoChave chave);


/*
* 5 - Inserção no fim de uma lista
* Insere nó no fim de uma lista dada a referência do ponteiro
* do primeiro nó.
* Devolve endereço do novo nó ou NULL em caso de
* insucesso.
*/
TipoListaSimples *insereFimListaSimples(TipoListaSimples **prim, TipoChave chave);


/*
* 6 - Remoção último nó
* Remove o último nó de uma lista (caso ele exista) dada a 
* referência do ponteiro do primeiro nó.
*/
void removeUltimoNo(TipoListaSimples **prim);


/*
* 7 - Remove nó por valor de chave
* Remove nó cujo valor chave seja igual a 'chave'
* Mantêm lista inalterada caso este não exista.
*/
void removeNo(TipoListaSimples **prim, TipoChave chave);


/*
* 8 - Remove todos nós
* Remove TODOS os nos da lista exceto e atualiza
* ponteiro para o primeiro para NULL.
* Dica: recursividade pode ajudar muito!
*/
void liberaNos(TipoListaSimples **prim);


/*
* 9 - Cria cópia 
* Cria uma nova lista cujos nós têm os mesmos
* valores da lista dada. Devolve o ponteiro para 
* o primeiro nó da nova lista. 
*/
TipoListaSimples *copiaListas(TipoListaSimples *prim);


/* 10 - Cria cópia 
* Calcula a interseção entre as duas listas
* dadas e insere tais nós numa (nova) terceira
* lista. Devolve o ponteiro para o cabeça da nova lista.
* A interseção deve considerar o campo chave.
*/
TipoListaSimples *intersecaoListas(TipoListaSimples *prim1, TipoListaSimples *prim2)
{
	TipoListaSimples *inter=NULL, *aux=NULL, *cont=NULL;
	int x=0;
	
//	inter = (TipoListaSimples *)malloc(sizeof(TipoListaSimples));
	cont = prim2;
	
	while (prim1!=NULL)
	{
		prim2 = cont;
		printf("=== prim1: %d ===\n", prim1->chave);
		while (prim2!=NULL)
		{
			printf("ola\n");
			printf("\t=== prim2: %d ===\n", prim2->chave);
			
			if (inter==NULL)
			{
				printf("xay\n");
				aux = pesquisaNo(prim1,prim2->chave);
				inter = insereFimListaSimples(&inter,aux->chave);
				printf("inter -- chave: %d, prox: NULL\n", inter->chave);
			}
			else
			{
				printf("oi\n");
				inter->prox = pesquisaNo(prim1,prim2->chave);
				inter->prox->prox = NULL;
				
				if (inter->prox!=NULL)
					inter = inter->prox;
				if (inter->prox!=NULL)
					printf("inter -- chave: %d, prox: %d\n", inter->chave, inter->prox->chave);
			}
			
			prim2 = prim2->prox;
		}
		printf("fim\n");
		prim1 = prim1->prox;
	}
	
	return inter;
	
	
	
	
	
//			if (prim1->chave == prim2->chave)
//			{
//				if (inter == NULL)
//				{
//					inter = (TipoListaSimples *)malloc(sizeof(TipoListaSimples));
//					printf("xau\n");
//					inter->chave = prim1->chave;
//					inter->valorQualquer = prim1->valorQualquer;
//					inter->prox = NULL;
//					printf("inter -- chave: %d, valor: %d, prox: NULL\n", inter->chave, inter->valorQualquer);
//				}
//				else
//				{
//					printf("oi\n");
//					if (inter->prox!=NULL)
//						printf("inter -- chave: %d, prox: %d\n", inter->chave, inter->prox->chave);
//					else
//						printf("inter -- chave: %d, prox: NULL\n", inter->chave);
//					
//					aux2->chave = prim2->chave;
//					aux2->valorQualquer = prim2->valorQualquer;
//					aux2->prox = NULL;
//					
//					while (inter->prox!=NULL)
//						inter = inter->prox;
//					
//					inter->prox = aux2;
//					printf("aux2 -- chave: %d\n", aux2->chave);
//					printf("inter -- chave: %d, prox: %d\n", inter->chave, inter->prox->chave);
//				}
//			}
	
}


//não necessário
void imprimeLista(TipoListaSimples *prim)
{
	while(prim!=NULL)
	{
		printf("chave: %d\n", prim->chave);
		printf("valor: %d\n", prim->valorQualquer);
		printf("endereco: %x\n", prim);
		prim = prim->prox;
	}
}

int main () 
{
	TipoListaSimples *prim=NULL, *no=NULL, *prim2=NULL;
	int keyp = 23;
	
	prim = insereInicioListaSimples(&prim,keyp,2020);
	prim = insereInicioListaSimples(&prim,7,2042);
	prim = insereInicioListaSimples(&prim,93,2056);
	prim = insereInicioListaSimples(&prim,54,2025);
	prim = insereInicioListaSimples(&prim,45,1993);
	prim = insereInicioListaSimples(&prim,13,1984);
	prim = insereInicioListaSimples(&prim,2,2025);
	
	prim2 = insereInicioListaSimples(&prim2,keyp,2020);
	prim2 = insereInicioListaSimples(&prim2,13,1984);
	prim2 = insereInicioListaSimples(&prim2,7,2042);
	prim2 = insereInicioListaSimples(&prim2,54,2025);
	prim2 = insereInicioListaSimples(&prim2,45,1993);
	prim2 = insereInicioListaSimples(&prim2,97,2001);
	prim2 = insereInicioListaSimples(&prim2,3,1997);
//	
//	printf("======= Lista 1 feita =======\n");
//	
//	imprimeLista(prim);
//	imprimeLista(prim2);
//// 1	lista normal
//	
//	printf("\n=== Atualizacao de valor ===\n");
//	TipoValor novoValor = 2016;
//	atualizaValor(prim,novoValor);
//	
//	imprimeLista(prim);
//// 2	lista com o primeiro valor atualizado
//	
//	printf("\n=== 1o da lista removido ===\n");
//	removePrimeiroNo(&prim);
//	imprimeLista(prim);
//// 3	removendo o primeiro objeto
//	
//	TipoListaSimples *achei=NULL;
//	int achar;
//	
//	printf("\n========= Pesquisa =========\n");
//	printf("Insira a chave: ");
//	scanf("%d", &achar);
//	
//	achei = pesquisaNo(prim,achar);
//	
//	if (achei != NULL)
//	{
//		printf("///---Encontrado!---///\n");
//		printf("chave: %d\n", achei->chave);
//		printf("valor: %d\n", achei->valorQualquer);
//		printf("endereco: %x\n", achei);
//	}
//	
//	else
//		printf("///---Nao encontrado!---///\n");
//// 4	pesquisa por chave
//	
//	printf("\n==== Inserindo no final ====\n");
//	TipoListaSimples *ulti=NULL;
//	
//	ulti = insereFimListaSimples(&prim,777);
//	
//	imprimeLista(ulti);
//	printf("\nLISTA COMPLETA:\n");
//	imprimeLista(prim);
////	5	inserindo no fim da lista
//	
//	printf("\n== Remove os dois ultimos ==\n");
//	
//	removeUltimoNo(&prim);
//	removeUltimoNo(&prim);
//	
//	imprimeLista(prim);
////	6	removendo os ultimos
//	
//	printf("\n==== Remove o escolhido ====\n");
//	
//	int rmkey;
//	
//	printf("Insira a chave do no: ");
//	scanf("%d", &rmkey);
//	
//	removeNo(&prim,rmkey);
//	
//	imprimeLista(prim);
//	7	removendo por chave
	
/*	printf("\n======== Libera nos ========\n");
	
	liberaNos(&prim);
	
	imprimeLista(prim);
	printf("Lista Vazia!\n");
//	8 remove todos os nós
*/	
	
	TipoListaSimples *copia=NULL;
	printf("\n====== Copia a lista 1 ======\n");
	
	copia = copiaListas(prim);
	if (copia==NULL) printf("SO nao liberou memoria!\n");
	
	printf("Copia:\n");
	imprimeLista(copia);
//	9 copia a lista
	TipoListaSimples *inter=NULL;
	
	
	printf("\n========= Lista 2 =========\n");
	imprimeLista(prim2);
	
	
	printf("\n===== Lista Intersecao =====\n");
	
	inter = intersecaoListas(prim,prim2);
	
//	imprimeLista(inter);
	
	return 0;
}

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
