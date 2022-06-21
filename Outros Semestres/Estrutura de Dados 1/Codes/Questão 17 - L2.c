#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calcula_media(float *matriz, float *vetor, int alunos, int notas);

int main()
{
	int alu, notas;
	
	printf("Quantidade de alunos: ");
	scanf("%d", &alu);
	printf("Quantidade de notas: ");
	scanf("%d", &notas);
	
	float mat[alu][notas], med[alu];
	int i, j;
	srand(time(NULL));
	
	printf("Preencha as notas:\n");
	for (i=0; i<alu; i++)
	{
		for (j=0; j<notas; j++)
		{
			mat[i][j] = rand()%10;
			printf("Aluno: %d %10 Avaliacao: %d\t Nota: %f\n", i+1, j+1, mat[i][j]);
		//	printf("Aluno: %d\t Avaliacao: %d\t Nota: ", i, j);
		//	scanf("%f", &mat[i][j]);
			fflush(stdin);
		}
		system("pause");
		system("cls");
	}
	
	calcula_media(mat,med,alu,notas);
	
	printf("Media:\n");
	for (i=0; i<alu; i++)
		printf("Aluno %d: %f\n", i+1, *(med+i));
		
	return 0;
}

void calcula_media(float *matriz, float *vetor, int alunos, int notas)
{
	int i, j, cont=0;
	
	for (i=0; i<alunos; i++)
	{
		/*zera o elemento da posi��o pra poder somar dentro do
		pr�ximo for*/
		*(vetor+i) = 0;
		for (j=0; j<notas; j++)
		{
			/*Soma todas as notas acumulando na posi��o
			vetor+i e incrementa cont para continuar somando
			as trilhas de mem�ria e nenhuma se sobrepor*/
			*(vetor+i) += *(matriz+cont);
			cont++;
		}
		//Calcula a m�dia;
		*(vetor+i) /= notas;
	}
}
