#include <stdio.h>
#include <math.h>

int main()
{
	int num;
	float sa, ia, sf;

	printf("Digite seu numerdo de identificacao: ");
	scanf("%d", &num);
	printf("Digite seu salario atual: R$");
	scanf("%f", &sa);
	
	if (sa >= 0)
	{
		if (sa <= 300.00)
		{
			ia = 1.1;
			sf = sa*ia;
			
			printf("Numero de ID: %d\n", num);
			printf("Salario atual: R$%.2f\n", sa);
			printf("Indice de aumento: 10\n");
			printf("Salario final: R$%.2f\n", sf);
		}
		if(sa > 300.00 && sa <= 600.00)
		{
			ia = 1.11;
			sf = sa*ia;
			
			printf("Numero de ID: %d\n", num);
			printf("Salario atual: R$%.2f\n", sa);
			printf("Indice de aumento: 11\n");
			printf("Salario final: R$%.2f\n", sf);
		}
		if (sa > 600.00 && sa <= 900.00)
		{
			ia = 1.12;
			sf = sa*ia;
			
			printf("Numero de ID: %d\n", num);
			printf("Salario atual: R$%.2f\n", sa);
			printf("Indice de aumento: 12\n");
			printf("Salario final: R$%.2f\n", sf);
		}
		if (sa > 900.00 && sa <= 1500.00)
		{
			ia = 1.06;
			sf = sa*ia;
			
			printf("Numero de ID: %d\n", num);
			printf("Salario atual: R$%.2f\n", sa);
			printf("Indice de aumento: 6\n");
			printf("Salario final: R$%.2f\n", sf);
		}
		if (sa > 1500.00 && sa <= 2000.00)
		{
			ia = 1.03;
			sf = sa*ia;
			
			printf("Numero de ID: %d\n", num);
			printf("Salario atual: R$%.2f\n", sa);
			printf("Indice de aumento: 3\n");
			printf("Salario final: R$%.2f\n", sf);
		}
		if (sa > 2000.00)
		{
			sf = sa;
			
			printf("Numero de ID: %d\n", num);
			printf("Salario atual: R$%.2f\n", sa);
			printf("Indice de aumento: 0\n");
			printf("Salario final: R$%.2f\n", sf);
		}
	}
	else
		printf("Valores invalidos.");
	
	return 0;
}
