#include <stdio.h>
#include <math.h>

float resto(float p, float qnt);
int reset();

int main()
{
	int i;
	float pr, qntr, res;

	do
	{
		printf("Insira o peso do saco de racao (em Kg):\n");
		scanf("%f", &pr);
		printf("Insira a quantidade fornecida para cada gato (em g):\n");
		scanf("%f", &qntr);
		
		if (pr > 0 && qntr > 0)
		{
			res = resto(pr,qntr);
			printf("Restara %.2fKg ou %.2fg de racao no saco\n", res/1000, res);
			i = reset();
		}
		else
		{
			printf("Valor invalido. Tente novamente\n");
			i = 1;
		}
		
	} while (i == 1);
	
	return 0;
}

float resto(float p, float qnt)
{
	int i=0;
	
	p *= 1000;	
	
	while (i < 5 && p > 0)
	{
		p -= qnt;
		if(p < 0)
			p = 0;
		i++;
	}
	return p;
}

int reset()
{
	int res;
RESET:
	fflush(stdin);
	printf("\nDeseja refazer o processo? (s/n)\n");
	scanf("%c", &res);
	
	switch (res)
	{
		case 's':
		case 'S':
			return res=1;
			break;
		
		case 'n':
		case 'N':
			printf("Ate mais!\n");
			break;
				
		default:
			printf("Opcao invalida.\n"); goto RESET;
			break;
	}
}
