#include <stdio.h>

/*
x = numero inteiro positivo,
i = contador,
d = possível divisor,
dv = divisor valido,
som = 
*/

int main()
{
	long long unsigned int x, i, d, dv, som;
	
	
	for (i=0; i < 10; i++)
	{
	X:
		printf("Insira x: ");
		scanf("%Lu", &x);
		
		som = 0;
		
		if (x >= 0)
		{
			printf("Divisor(es) valido(s):\n");
			
			for (d=1; d <= (x/2); d++)
			{
				if ((x%d) == 0)
				{
					dv = d;
					som = som+dv;
					printf("+%d", dv);
				}
			}
			printf(" = %Lu\n", som);
			
			if (som == x)
					printf("%Lu eh um numero perfeito!\n", x);
				else
					printf("%Lu nao eh um numero perfeito!\n", x);
		}
		else
		{
			printf("Invalido. Tente novamente\n");
			goto X;
		}
	}
}
