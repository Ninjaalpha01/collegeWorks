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
Tpaciente *insereFim(char nome[], int senha, int idade,Tpaciente *paux)
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
	while(paux!=NULL)
	{
		printf("\n%s", paux->nome);
		printf("\n%d", paux->senha);
		paux = paux->prox;
	}
	
}

//void removeInicio(Tpaciente **paux)
Tpaciente *removeInicio(Tpaciente *paux)
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

Tpaciente *buscaNo(Tpaciente *p, int k)
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
}
int main()
{
	Tpaciente *inicio=NULL, *final=NULL, *achou;
	int op=1,chave, senha=1, idade;
	char nome[15];
	while(op!=5)
	{
		printf("\n1 - Insere paciente na fila");
		printf("\n2 - Atendimento medico - Retira da fila");
		printf("\n3 - Imprime");
		printf("\n4 - Atendimento prioritario");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				{
				    printf("\nInforme nome:");
				    scanf("%s",&nome);
					printf("\nInforme idade:");
				    scanf("%d",&idade);
					final = insereFim(nome, senha, idade,final);
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
					   	   inicio=removeInicio(inicio);
					   	   if(inicio == NULL) 
					   	   	  final = NULL;
					   }
				}break;
			case 3:
				{
				  if(inicio==NULL)
					   printf("\nLista vazia!");
				  imprimeLista(inicio);	
				}break;
			case 4:
				{
					achou=buscaNo(inicio,70);
					if(achou!=inicio)
					{
						achou->prox = inicio;
						inicio = achou;
					}
				}				
		}
	}
}
