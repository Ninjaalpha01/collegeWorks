#include <stdio.h>

int main()
{
	char s;
	int id, qntl, sum_l, sum_m, sum_id, cth, qntp, pt;
	float per, med_h;
	
	id = 0;
	qntl = 0;
	sum_l = 0;
	sum_m = 0;
	sum_id = 0;
	qntp = 0;
	pt = 0;
	cth = 0;
	
	while (id >= 0)
	{	
		pt++;
		if (id < 10 && id > 0)
			sum_l = sum_l+qntl;
		
		switch (s)
		{
			case 'F':
			case 'f':
				{	
					if (qntl >= 5)
					{
						sum_m++;
					}
				}
			break;
			
			case 'M':
			case 'm':
				{	
					if (qntl < 5)
					{
						sum_id = sum_id+id;
						cth++;
					}
				}
			break;
		}
			
		printf("Insira sua idade: ");
		scanf("%d", &id);
		if (id >= 0)
		{
			fflush(stdin);
			printf("Insira seu sexo (m/f): ");
			scanf("%c", &s);
			printf("Insira a quantidade de livros que leu em 2010: ");
			scanf("%d", &qntl);
			
			if (qntl == 0)
			qntp++;
		}
	}
	med_h = 1.0*sum_id/cth;
	per = ((float)qntp/pt)*100;
	
	printf("\nQuantidade total de livros que menores de 10 anos leram: %d\n", sum_l);
	printf("Quantidade de mulheres que leram 5 ou mais livros: %d\n", sum_m);
	
	if (med_h >= 0)
		printf("Media de idade dos homens que leram menos que 5 livros: %.1f anos\n", med_h);
		
	printf("Percentual de pessoas que nao leram livros: %%%.2f\n", per);
}
