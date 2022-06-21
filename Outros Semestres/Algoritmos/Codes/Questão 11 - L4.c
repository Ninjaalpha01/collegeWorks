#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
id = idade,
ser = serie,
qntl = qntd de livros lidos/mes,
s3s = soma de alunos da 3 serie,
ml4 = maior qntd de livros lidos por um aluno da 4 serie,
red = redação,
per = percentual de alunos que não gostam de fazer redação (3 serie),
med_id = media de idade dos alunos da 1 e 2 serie,
sp = soma para a percentagem,
sid = soma de idades,
al = alunos da 1 e 2 serie.
*/

int main()
{
	int id, ser, qntl, s3s, ml4, sp, sid, al;
	int red;
	float per, med_id;
	
	id = 1;
	al = 0;
	sp = 0;
	s3s = 0;
	ml4 = 0;
	qntl = 0;
	
	
	while (id > 0)
	{
		printf("Insira sua idade: ");
		scanf("%d", &id);
		
		if (id > 0)
		{
			printf("Insira sua serie: \n");
			printf("1 - primeira, 2 - segunda, 3 - terceira, 4 - quarta\n");
			scanf("%d", &ser);
			printf("Insira quantos livros voce le por mes: ");
			scanf("%d", &qntl);
			printf("Gosta de fazer redacao? (1 - sim / 0 - nao)\n");
			scanf("%d", &red);
			
			switch (ser)
			{
				case 1:
					{
					sid = sid+id;
					al++;
					}
					break;
				case 2:
					{
					sid = sid+id;
					al++;
					}
					break;
				case 3:
					{
						s3s++;
						
						if (red == 0)
						{
							sp++;
						}
					}
					break;
				case 4:
					{
						if (ml4 < qntl)
							ml4 = qntl;
					}
					break;
				default:
					printf("Erro\n");
					break;
			}
		}
		fflush(stdin);
	}
	per = ((float)sp/s3s)*100;
	med_id = (float)sid/al;
	
	printf("\n\nQuantidade de alunos na terceira serie: %d\n", s3s);
	printf("\nA maior quantidade de livros lidos por um aluno (4 serie)eh: %d\n", ml4);
	printf("\nA porcentagem de alunos que nao gostam de fazer redacao e que estao na 3 serie eh: %.2f%%\n", per);
	if (med_id > 0)
		printf("\nA media de idade dos alunos da 1 e 2 serie eh: %.1f\n", med_id);
	else
		printf("\nNao existem alunos na 1 ou 2 serie");
}
