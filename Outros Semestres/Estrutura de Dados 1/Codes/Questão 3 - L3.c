#include <stdio.h>
#include <stdlib.h>
#include "gabriel.c"

typedef struct
{
	long int matricula;
	char nome[40];
	float nota1;
	float nota2;
	float nota3;
	float media;
} Tipoaluno;

void inserealu(Tipoaluno *aluno, int n);
char *maior_nota1(Tipoaluno *aluno, int n);
char *maior_media(Tipoaluno *aluno, int n);
char *menor_media(Tipoaluno *aluno, int n);
char *aprovacao(Tipoaluno *aluno, int n);

int main()
{
	int i, n=5;
	char *max_n1, *max, *min, *sit;
	Tipoaluno aluno[n];
	
	inserealu(aluno,n);
	
	max_n1 = maior_nota1(aluno,n);
	max = maior_media(aluno,n);
	min = menor_media(aluno,n);
	
	system("pause");
	system("cls");
	
	printf("Aluno com maior nota da Prova 1: %s", max_n1);
	printf("Aluno com maior media: %s", max);
	printf("Aluno com menor media: %s", min);
	
	system("pause");
	system("cls");
	
	for (i=0; i<n; i++)
	{
		printf("Aluno: %s", aluno[i].nome);
		sit = aprovacao(aluno+i,n);
		printf("Situacao: %s\n", sit);
		printf("Media: %f\n\n", aluno[i].media);
	}
	
	return 0;
}

void inserealu(Tipoaluno *aluno, int n)
{
	int i, j;
	float med;
	
	for (i=0; i<n; i++)
	{
		printf("--- Dados aluno %d ---\n", i+1);
		printf("Matricula: ");
		scanf("%ld", &aluno[i].matricula);
		fflush(stdin);
		printf("Nome: ");
		fgets(aluno[i].nome,40,stdin);
		fflush(stdin);
		printf("-- Notas --\n");
		
		do
		{
			printf("Prova 1: ");
			scanf("%f", &aluno[i].nota1);
			fflush(stdin);
		} while (aluno[i].nota1 < 0 || aluno[i].nota1 > 10);
		
		do
		{
			printf("Prova 2: ");
			scanf("%f", &aluno[i].nota2);
			fflush(stdin);
		} while (aluno[i].nota2 < 0 || aluno[i].nota2 > 10);
		
		do
		{
			printf("Prova 3: ");
			scanf("%f", &aluno[i].nota3);
			fflush(stdin);
		} while (aluno[i].nota3 < 0 || aluno[i].nota3 > 10);
		
		aluno[i].media = (aluno[i].nota1+aluno[i].nota2+aluno[i].nota3)/3;
		
		printf("\n");
	}
}

char *maior_nota1(Tipoaluno *aluno, int n)
{
	int i, maior=0;
	char *p=NULL;
	
	for (i=1; i<n; i++)
		if (aluno[i].nota1 >= aluno[maior].nota1)
			maior = i;
	
	p = aluno[maior].nome;
	
	return p;
}

char *maior_media(Tipoaluno *aluno, int n)
{
	int i, maior=0;
	char *p=NULL;
	
	for (i=1; i<n; i++)
		if (aluno[i].media >= aluno[maior].media)
			maior = i;
	
	p = aluno[maior].nome;
	
	return p;
}

char *menor_media(Tipoaluno *aluno, int n)
{
	int i, menor=0;
	char *p=NULL;
	
	for (i=1; i<n; i++)
		if (aluno[i].media <= aluno[menor].media)
			menor = i;
	
	p = aluno[menor].nome;
	
	return p;
}
char *aprovacao(Tipoaluno *aluno, int n)
{
	int i;
	char *p=NULL;
	
	for (i=0; i<n; i++)
	{
		if (aluno[i].media >= 6)
		{
			p = (char *)malloc(9 * sizeof(char));
			p = "APROVADO";
			
			return p;
		}
			
		else
		{
			p = (char *)malloc(10 * sizeof(char));
			p = "REPROVADO";
			
			return p;
		}
	}
	
}
