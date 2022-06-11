#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	float a, b, c;
	
	printf("Insira i: ");
	scanf ("%d", &i);
	printf("Insira a, b e c:\n");
	scanf("%f%f%f", &a, &b, &c);
	
	float maior, meio, menor;
	
	if (a >= b && a >= c)
	{
		maior = a;
		
		if (b > c)
		{
			meio = b;
			menor = c;
		}
		else
		{
			meio = c;
			menor = b;
		}
	}
	else
	{
		if (b >= a && b >= c)
		{
			maior = b;
			
			if (a > c)
			{
				meio = a;
				menor = c;
			}
			else
			{
				meio = c;
				menor = a;
			}
		}
		else
		{
			if (c >= a && c >= b)
			{
				maior = c;
				
				if (a > b)
				{
					meio = a;
					menor = b;
				}
				else
				{
					meio = b;
					menor = a;
				}
			}
		}
	}
	
	if (i == 1)
	{
		printf("%.2f, %.2f, %.2f", menor, meio, maior);
	}
	else
	{
			if (i == 2)
			{
				printf("%.2f, %.2f, %.2f", maior, meio, menor);
			}
			else
			{
				if (i == 3)
				{
					printf("%.2f, %.2f, %.2f", meio, maior, menor);
				}
				else
					printf("Opcao invalida");	
			}
	}
}
