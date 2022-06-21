//Gabriel Leonardo M de Oliveira RA:a2317940

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nome[15];
	int namigos;
	char *list;
} Tipouser;

void preencher(Tipouser *v);
void popularidade(Tipouser *v, int *p, int n);

int main()
{
	int n, i, j;
		
	printf("** n **\n");
	scanf("%d", &n);
	fflush(stdin);
	
	Tipouser user[n];
	int popu[n];
	
	for (i=0; i<n; i++)
	{
		printf("\n** Usuario %d (nome/quantidade/amigos) **\n", i);
		preencher(user+i);
	}
	
	//LIMPAR A TELA
	system("pause");
	system("cls");
	
	printf("\n** Popularidade **\n");
	popularidade(user,popu,n);
	
	for (i=0; i<n; i++)
		printf("%s%d\n", user[i].nome, *(popu+i));
	
	for(i=0; i<n; i++)
		free(user[i].list);
	
	return 0;
}

void preencher(Tipouser *user)
{
	int i;
	
	printf("Nome: ");
	fgets(user->nome,15,stdin);
	fflush(stdin);
	printf("Amigos: ");
	scanf("%d", &user->namigos);
	fflush(stdin);
	
	user->list = (char *)malloc(user->namigos * 15 * sizeof(char));
	
	printf("Lista de amigos:\n");
	i=0;
	while (i<(user->namigos*15))
	{
		fgets(user->list+i,15,stdin);
		i+=15;
	}
}

void popularidade(Tipouser *user, int *p, int n)
{
	int i, j, k, qnt, compara;
	char *pont;
	
	for (i=0; i<n; i++)
	{
		qnt = 0;
		for (j=0; j<n; j++)
			for (k=0; k<user[j].namigos; k++)
				if ((strcmp(user[i].nome,(user[j].list+k*15))) == 0)
					qnt++;
		*(p+i) = qnt;
	}
}
