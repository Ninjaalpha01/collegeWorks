#include <stdio.h>

int main()
{
	int f;
	float p, sal;
	
	for (f=1; f<=1000; f++)
	{
	SAL:
		printf("Insira seu salario: R$");
		scanf("%f", &sal);
		
		if (sal > 0)
		{
			if (sal < 10000)
			{
				printf("O reajuste sera de 55%%\n");
				sal = sal*1.55;
				printf("Salario final: R$%.2f\n\n", sal);
			}
			else
			{
				if (sal <= 25000)
				{
					printf("O reajuste sera de 30%%\n");
					sal = sal*1.30;
					printf("Salario final: R$%.2f\n\n", sal);
				}
				else
				{
					printf("O reajuste sera de 20%%\n");
					sal = sal*1.20;
					printf("Salario final: R$%.2f\n\n", sal);
				}
			}
		}
		else
		{
			printf("Tente novamente\n");
			goto SAL;
		}
	}
}
