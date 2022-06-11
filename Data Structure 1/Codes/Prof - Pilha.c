#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct paciente{
	char nome[15];
	int senha, idade;
	struct paciente *prox;
}Tpaciente;

Tpaciente *alocaNo(char nome[], int senha, int idade)
{
	Tpaciente *novo;
	novo = (Tpaciente *)malloc(sizeof(Tpaciente));
	if (novo == NULL) return NULL;
	strcpy(novo->nome, nome);
	novo->senha = senha;
	novo->idade = idade;
	novo->prox = NULL;
	return novo; 
}
//void insereFim(char nome[], int senha, int idade,Tpaciente **paux)
Tpaciente *enfileirar(char nome[], int senha, int idade,Tpaciente *paux)
{
	Tpaciente *novo;
	novo = alocaNo(nome, senha, idade);
	if(novo==NULL) return NULL;
	if(paux != NULL) //(*paux != NULL)
	   paux->prox = novo;
	return novo;
	// n?o tem return *paux = novo;	
}

void imprimeLista(Tpaciente *paux)
{
	
	if(paux==NULL) printf("\nLista vazia...");
	while(paux!=NULL)
	{
		printf("\n%s", paux->nome);
		printf("\n%d", paux->senha);
		paux = paux->prox;
	}
	
}

//void removeInicio(Tpaciente **paux)
Tpaciente *desenfileirar(Tpaciente *paux)
{
   Tpaciente *aux= paux;
   
   if(paux->prox!=NULL)
     {
        paux = paux->prox; //*paux = *paux->prox;
        free(aux);
        return paux; 
	 }
    else
    {
    	free(aux);
    	return NULL; //*paux = NULL;
	}   
}
//insere no in?cio
void empilha(char nome[], int senha, int idade,Tpaciente **p)
{
	Tpaciente *novo;
	novo = alocaNo(nome, senha, idade);
	if(novo==NULL) return ;
	else
	{
		novo->prox = *p;
		*p = novo;
	}
}

//remove no in?cio
void desempilha(Tpaciente **p)
{
	Tpaciente *paux=*p;
	if(*p==NULL) printf("\nLista vazia!");
	else
	{
		*p = (*p)->prox;
		free(paux);
		paux=NULL;
	}
}
//remover toda a fila para a pilha -->removendo inicio fila (f - inicio fila / ffim - final da fila)
void filaPilha(Tpaciente **f, Tpaciente **p, Tpaciente **ffim)
{
	if(*f == NULL) 
		printf("\nFila vazia...");
	else
	{
		while(*f!=NULL)//um por um --> tira o la?o de repeti??o
		{
			empilha((*f)->nome, (*f)->senha, (*f)->idade, p);
			*f = desenfileirar(*f);
		}
		if(*f==NULL)
			  *ffim = NULL;
		
	}
}
//f final da fila - i in?cio da fila
void pilhaFila(Tpaciente **p, Tpaciente **f, Tpaciente **i)
{
	if(*p == NULL) 
		printf("\nPilha vazia...");
	else
	{
		while(*p!=NULL)
		{
			*f = enfileirar((*p)->nome, (*p)->senha, (*p)->idade, *f);
			if(*i == NULL) //s? quando enfileirar o 1o.
				*i = *f;
			desempilha(p);
		}
	}
}
int main()
{
	Tpaciente *inicio=NULL, *final=NULL, *achou, *topo=NULL;
	int op=1,chave, senha=1, idade, op2=1;;
	char nome[15];
	while(op!=9)
	{
		printf("\n1 - Insere paciente na fila - enqueue");
		printf("\n2 - Atendimento medico - Retira da fila - dequeue");
		printf("\n3 - Imprime Fila");
		printf("\n4 - Empilha paciente - push");
		printf("\n5 - Desempilha paciente - pop");
		printf("\n6 - Imprime Pilha");
		printf("\n7 - Fila --> Pilha");
		printf("\n8 - Pilha --> Fila");
		printf("\n9 - Sair");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				{
				    printf("\nInforme nome:");
				    scanf("%s",&nome);
					printf("\nInforme idade:");
				    scanf("%d",&idade);
					final = enfileirar(nome, senha, idade,final);
				    if(inicio == NULL) 
					   inicio = final;
					senha++;
				}break;
			case 2:
				{
					if(inicio==NULL)
					   printf("\nLista vazia!");
					else
					   {
					   	   inicio=desenfileirar(inicio);
					   	   if(inicio == NULL) 
					   	   	  final = NULL;
					   }
				}break;
			case 3:
				{
				  if(inicio==NULL)
					   printf("\nLista vazia!");
				  else imprimeLista(inicio);		
				}break;
			case 4:
				{
					printf("\nInforme nome:");
				    scanf("%s",&nome);
					printf("\nInforme idade:");
				    scanf("%d",&idade);
					empilha(nome, senha, idade,&topo);
					printf("\n%d", topo->idade);
				}break;
			case 5:
				{
					desempilha(&topo);
				}break;
			case 6:
				{
					imprimeLista(topo);
				}break;
			case 7:
				{
					filaPilha(&inicio,&topo,&final);
				}break;
			case 8:
				{
					pilhaFila(&topo,&final,&inicio);
				}break;
		}
	}
}


/*Tpaciente *buscaNo(Tpaciente *p, int k)
{
	Tpaciente *ant=p;
	if(p==NULL) printf("\nLista Vazia!");
	else
	{
		while(p!=NULL)
		{
			if(p->idade >= k)
			{
				ant->prox = p->prox;
				return p;
			}
			ant = p;   
			p = p->prox;
		}
		return NULL;
	}
}*/
