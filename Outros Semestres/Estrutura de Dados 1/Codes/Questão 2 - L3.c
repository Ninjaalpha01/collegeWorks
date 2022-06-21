#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
	int dia, mes, ano;
} Tipodata;

typedef struct agenda
{
	char compromisso[60];
	Tipodata data;
} Tipoagenda;

void inserevet(Tipoagenda *v);
void inseredata(Tipoagenda *v);
//void vordem(Tipoagenda *v, int tam);

int main()
{
	int n, i, j=1, m, a;
	
	printf("Insira n: ");
	scanf("%d", &n);
	
	Tipoagenda vet[n];
	Tipodata dat;
	
	for (i=0; i<n; i++)
	{
		inserevet(vet+i);
		inseredata(vet+i);
	}
	
	system("pause");
	system("cls");
	
	printf("Insira (mes/ano) para mostrar os compromissos:\n");
	scanf("%d/%d", &m, &a);
	
	system("pause");
	system("cls");
	
	printf("Compromissos ate %d/%d:\n", m, a);
	for (; m!=0; m--)
		for (i=0; i<n; i++)
			if (vet[i].data.mes == m)
				if (vet[i].data.ano == a)
				{
					printf("%d - %s ", j, vet[i].compromisso);
					printf("%d/%d/%d\n\n", vet[i].data.dia, vet[i].data.mes, vet[i].data.ano);
					j++;
				}
	return 0;
}

void inserevet(Tipoagenda *v)
{
	fflush(stdin);
	printf("Insira compromisso: ");
	fgets(v->compromisso,60,stdin);
	fflush(stdin);
}

void inseredata(Tipoagenda *v)
{
	do
	{
		printf("Insira data:\n");
		printf("Dia: ");
		scanf("%d", &v->data.dia);
		fflush(stdin);
	} while (v->data.dia <=0 || v->data.dia > 31);
	
	do
	{
		printf("Mes: ");
		scanf("%d", &v->data.mes);
		fflush(stdin);
	} while (v->data.mes <= 0 || v->data.mes > 12);
	
	do
	{
		printf("Ano: ");
		scanf("%d", &v->data.ano);
		fflush(stdin);
	} while (v->data.ano < 2021 || v->data.ano > 2050);
}
/*
ordenar o vetor com os compromissos em ordem datada
void vordem(Tipoagenda *v, int tam)
{
	Tipoagenda *cop;
	int maiord, maiorm;
	int i, j;
	
	cop = (Tipoagenda *)malloc(tam * sizeof(Tipoagenda));
	
	maiord = *v->data.dia;
	maiorm = *v->data.mes;
	
	for (i=0; i<tam; i++)
	{
		for (j=0; j<tam; j++)
			if (*v+j->data.dia >= maiord)
				*cop+i = *v+j->data.dia;
	}
}*/
