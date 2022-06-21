#include <stdio.h>

int main()
{
	int p, id, qnti, qntj, somh;
	float alt, med, maior;
	
	qnti = 0;
	qntj = 0;
	somh = 0;
	maior = 0;
	
	for (p=1; p<=15; p++)
	{
	ID:
		printf("Insira sua idade: ");
		scanf("%d", &id);
		
		if (id >= 0)
		{
		ALT:
			printf("Insira sua altura: ");
			scanf("%f", &alt);
			
			if (alt >= 0)
			{
				if (maior < alt)
					maior = alt;
					
				if (id > 50)
					qnti++;
				else
					if (id >= 10 && id <= 20)
						{
							somh = somh+alt;
							qntj++;
						}
			}
			else
			{
				printf("Erro\nTente novamente\n");
				goto ALT;
			}
			
		}
		else
		{
			printf("Erro\nTente novamente\n");
			goto ID;
		}
	}
	printf("som = %d\tqntj = %d\n", somh, qntj);
	med = (float)somh/qntj;
		
	printf("Quantidade de pessoas com mais de 50 anos: %d\n", qnti);
	printf("Media de altura das pessoas com idade entre 10 e 20 anos: %.2f\n", med);
	printf("Maior altura registrada: %.2f", maior);
}
