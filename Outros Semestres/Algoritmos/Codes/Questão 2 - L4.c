#include <stdio.h>
#include <math.h>

int main()
{
	int x, p;
	
	printf("Insira x!:\n");
	scanf("%d", &x);
	
	p = 1;
	
	if (x > 0)
	{
		while (x > 0)
		{
			p = p*x;
			x--;
		}	
	printf("O numero fatorial eh igual a:\n");
	printf("%d", p);
	}
	
	else
		printf("Numero invalido");
}
