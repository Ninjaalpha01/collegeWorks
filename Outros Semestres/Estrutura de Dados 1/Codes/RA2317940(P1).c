//Gabriel Leonardo Martins de Oliveira - RA:a2317940 - P1 - Estrutura de Dados 1
#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
	char nome[20], vacina[15];
	int doses[2];
}TPessoa;

typedef struct agenda {
	int dia;
	int qtde;
	TPessoa *pessoa;
} TAgenda;

TAgenda *aloca_agenda(int tam);
TPessoa *aloca_atendimentos(int atendimentos);
void armazena_pessoa(TPessoa *pes);
void imprime_pessoa(int dia, TAgenda *prim);
void desaloca_atendimentos(int dia, TAgenda *prim);

int main()
{
	int tam, opc, dia;
	int x=1, i, j; //contadores
	
	TAgenda *prim=NULL; //Ponteiro que olha o vetor de TAgenda
	TPessoa *pes=NULL; //Ponteiro que olha o vetor de TPessoa
	
	printf("Informe numero de dias da agenda: ");
	scanf("%d", &tam);
	system("cls");
	
	do
	{
		printf("===NAO SE ESQUECA DE ALOCAR ANTES DE USAR===\n");
		printf("Insira uma opcao:\n");
		printf("1 - Alocar agenda\n");
		printf("2 - Alocar atendimentos\n");
		printf("3 - Armazenar pessoa\n");
		printf("4 - Imprimir pessoa\n");
		printf("5 - Desalocar atendimentos\n");
		printf("6 - Quit\n");
		scanf("%d", &opc);
		system("cls");
		
		switch (opc)
		{
			case 1:
			{
				prim = aloca_agenda(tam);
			} break;
			
			case 2:
			{
				printf("Insira a quantidade de atendimentos\n");
				for (i=0; i<tam; i++)
				{
					printf("Dia %d: ", i+1);
					scanf("%d", &prim[i].qtde);
					pes = aloca_atendimentos(prim[i].qtde);
					prim[i].pessoa = pes;
				}
				printf("\n\n");
				system("pause");
				system("cls");
			} break;
			
			case 3:
			{
				for (i=0; i<tam; i++)
				{
					printf("Dia %d\n", i+1);
					for (j=0; j<prim[i].qtde; j++)
					{
						armazena_pessoa(prim[i].pessoa+j);
					}
				}
				printf("\n\n");	
				system("pause");
				system("cls");
			} break;
			
			case 4:
			{
				do
				{
					printf("Informe o dia: ");
					scanf("%d", &dia);
					fflush(stdin);
					dia--;
				} while (dia<0 || dia>=tam);
				imprime_pessoa(dia,prim);
				printf("\n\n");
				system("pause");
				system("cls");
			} break;
			
			case 5:
			{
				do
				{
					printf("Insira o dia: ");
					scanf("%d", &dia);
					dia--;
				} while (dia<0 || dia>=tam);
				desaloca_atendimentos(dia,prim);
				system("cls");
			} break;
			
			case 6:
			{
				x = 0;
				printf("Obrigado!\n");
			}
				break;
			
			default:
				printf("Escolha invalida!\n");
		}
	} while (x);
	
	return 0;
}

TAgenda *aloca_agenda(int tam)
{
	TAgenda *aux=NULL;
	
	aux = (TAgenda *)malloc(sizeof(TAgenda)*tam);
	
	return aux;
}

TPessoa *aloca_atendimentos(int atendimentos)
{
	TPessoa *aux=NULL;
	
	aux = (TPessoa *)malloc(sizeof(TPessoa)*atendimentos);
	
	return aux;
}

void armazena_pessoa(TPessoa *pes)
{
	int dose;
	
	printf("Preencha:\n");
	
	fflush(stdin);
	printf("Nome: ");
	fgets(pes->nome,20,stdin);
	fflush(stdin);
	
	printf("Vacina: ");
	fgets(pes->vacina,15,stdin);
	fflush(stdin);
	
	DOSE:
	fflush(stdin);
	printf("Doses(1 ou 2): ");
	scanf("%d", &dose);
	if (dose == 1)
	{
		pes->doses[0] = 1;
		pes->doses[1] = 0;
	}
	else
		if (dose == 2)
		{
			pes->doses[0] = 1;
			pes->doses[1] = 1;
		}
		else
			goto DOSE;
}

void imprime_pessoa(int dia, TAgenda *prim)
{
	int i;
	
	if (prim[dia].pessoa == NULL)
		printf("Nao ha atendimentos nesse dia!\n");
	else
	{
		for (i=0; i<prim[dia].qtde; i++)
		{
			printf("\n===Pessoa %d===\n", i+1);
			printf("Nome: %s", prim[dia].pessoa[i].nome);
			printf("Vacina: %s", prim[dia].pessoa[i].vacina);
			printf("Doses: ");
			if (prim[dia].pessoa[i].doses[0]==1 && prim[dia].pessoa[i].doses[1]==1)
				printf("%d\n", 2);
			else
				printf("%d\n", 1);
		}
	}
}

void desaloca_atendimentos(int dia, TAgenda *prim)
{
	free(prim[dia].pessoa);
	prim[dia].pessoa = NULL;
}
